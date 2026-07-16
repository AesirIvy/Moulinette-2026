#include <dirent.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include "mostima.h"

void check_norminette(char* path) {
	char log[BUF_SIZE];
	char cmd[OUT_SIZE];

	snprintf(log, sizeof(log), "log.txt");
	snprintf(cmd, sizeof(cmd), "norminette %s >%s 2>&1", path, log);
	if (system(cmd) != 0) {
		printf(TAB "Norminette" NTAB RED "KO" RESET "\n\n");
		FILE *fp = fopen(log, "r");
		if (!fp) {
			fprintf(stderr, RED "check_norminette: fopen log.txt: %s\n" RESET, strerror(errno));
			exit(EXIT_FAILURE);
		}
		char line[BUF_SIZE];
		while (fgets(line, sizeof(line), fp))
			fputs(line, stderr);
		fclose(fp);
		remove(log);
		exit(EXIT_FAILURE);
	}
	printf(TAB "Norminette" NTAB GREEN "OK" RESET "\n");
	remove(log);
	return;
}

void check_allowed_files(const char* dir, char** expected, char** allowed_ext) {
	struct stat st;

	if (expected) {
		for (char** ep = expected; *ep != NULL; ++ep) {
			char path[PATH_MAX];
			snprintf(path, sizeof(path), "%s/%s", dir, *ep);
			if (stat(path, &st) != 0) {
				fprintf(stderr, TAB "Allowed files" FTAB RED "KO" RESET "\n\n");
				printf("the file '%s' is expected\n", *ep);
				exit(EXIT_FAILURE);
			}
			if (!S_ISREG(st.st_mode)) {
				fprintf(stderr, TAB "Allowed files" FTAB RED "KO" RESET "\n\n");
				printf("'%s' is not a regular file", *ep);
				exit(EXIT_FAILURE);
			}
		}
	}
	
	DIR *dp = opendir(dir);
	if (!dp) {
		fprintf(stderr, RED "check_expected_files: opendir: %s\n" RESET, strerror(errno));
		exit(EXIT_FAILURE);
	}
	struct dirent *entry;
	while ((entry = readdir(dp)) != NULL) {
		if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
			continue;
		bool is_expected = false;
		if (expected) {
			for (char** ep = expected; *ep != NULL; ++ep) {
				if (strcmp(entry->d_name, *ep) == 0) {
					is_expected = 1;
					break;
				}
			}
		}
		if (is_expected)
			continue;
		if (allowed_ext) {
			const char *dot = strrchr(entry->d_name, '.');
			if (dot) {
				bool allowed = false;
				for (char** ap = allowed_ext; *ap != NULL; ++ap) {
					if (strcmp(dot, *ap) == 0) {
						allowed = true;
						break;
					}
				}
				if (allowed)
					continue;
			}
		}
		fprintf(stderr, TAB "Allowed files" FTAB RED "KO" RESET "\n\n");
		printf("the file '%s' must not be present\n", entry->d_name);
		closedir(dp);
		exit(EXIT_FAILURE);
	}
	printf(TAB "Allowed files" FTAB GREEN "OK" RESET "\n");
	closedir(dp);
}

void check_allowed_functions(const char* dir, char** allowed_func) {
	DIR *dp = opendir(dir);
	if (!dp) {
		fprintf(stderr, RED "check_allowed_functions: %s: %s\n" RESET, dir, strerror(errno));
		exit(EXIT_FAILURE);
	}

	struct dirent *entry;
	while ((entry = readdir(dp))) {
		const char* name = entry->d_name;
		size_t len = strlen(name);
		if (len < 3 || strcmp(name + len - 2, ".c") != 0)
			continue;
			
		char src[BUF_SIZE];
		snprintf(src, sizeof(src), "%s/%s", dir, name);
		char obj[BUF_SIZE];
		snprintf(obj, sizeof(obj), "/tmp/%s.o", name);
		char cmd[OUT_SIZE];
		snprintf(cmd, sizeof(cmd), "cc -Wall -Wextra -Werror -c %s -o %s > /dev/null", src, obj);
		if (system(cmd) != 0) {
			fprintf(stderr, TAB "Allowed functions" FNTAB RED "KO" RESET "\n\n");
			printf("Compilation failed for '%s'\n", src);
			exit(EXIT_FAILURE);
		}

		snprintf(cmd, sizeof(cmd), "nm -u %s | awk '{print $NF}'", obj);
		FILE *fp = popen(cmd, "r");
		if (!fp) {
			fprintf(stderr, RED "check_allowed_functions: %s: %s\n" RESET, name, strerror(errno));
			remove(obj);
			exit(EXIT_FAILURE);
		}

		char symbol[BUF_SIZE];
		while (fgets(symbol, sizeof(symbol), fp)) {
			symbol[strcspn(symbol, "\n")] = '\0';
			if (symbol[0] == '\0')
				continue;

			bool allowed = false;
			if (allowed_func) {
				for (char** ap = allowed_func; *ap != NULL; ++ap) {
					if (strcmp(symbol, *ap) == 0) {
						allowed = true;
						break;
					}
				}
			}
			if (!allowed) {
				fprintf(stderr, TAB "Allowed functions" FNTAB RED "KO" RESET "\n\n");
				printf("Forbidden function '%s' called in '%s'\n", symbol, name);
				pclose(fp);
				remove(obj);
				exit(EXIT_FAILURE);
			}
		}
		pclose(fp);
		remove(obj);
	}
	fprintf(stderr, TAB "Allowed functions" FNTAB GREEN "OK" RESET "\n");
	closedir(dp);
}

void check() {
	DIR *dp = opendir("ex0");
	if (!dp) {
		fprintf(stderr, RED "check: ex0: %s\n" RESET, strerror(errno));
		exit(EXIT_FAILURE);
	}

	int i;
	int ref_amt = 1;
	char* refs[] = {
		"ft_ft.c",
		"ft_str_is_alpha.c",
		"ft_foreach.c",
		"ft_strdup.c",
		"ft_print_program_name.c",
		"ft_strcpy.c",
		"ft_point.h",
		"Makefile"
	};
	struct dirent* entry;
	while ((entry = readdir(dp))) {
		i = 0;
		while (i < ref_amt) {
			if (strcmp(entry->d_name, refs[i]) == 0)
				break;
			++i;
		}
		if (i < ref_amt)
			break;
	}
	closedir(dp);

	if (i == 0)
		check_c_pointers();
	else {
		printf("%d\n", i);
		fprintf(stderr, RED "couldn't determine the project\n" RESET);
	}
}


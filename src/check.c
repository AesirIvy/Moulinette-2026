#include <dirent.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include "mostima.h"

void check_norminette(char* path, char* flag) {
	char log[BUF_SIZE];
	char cmd[OUT_SIZE];

	snprintf(log, sizeof(log), "log.txt");
	snprintf(cmd, sizeof(cmd), "norminette %s %s >%s 2>&1", path, flag, log);
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

void check_allowed_functions(const char* dir, const char* test_path, char* allowed_func) {
	char cmd[BUF_SIZE];
	snprintf(cmd, sizeof(cmd), "bash %s/res/script/is_cheating.sh %s %s %s",
		get_self_path(), dir, test_path, allowed_func);

	FILE *fp = popen(cmd, "r");
	if (!fp) {
		fprintf(stderr, RED "check_allowed_functions: popen is_cheating.sh: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

	char output[BUF_SIZE];
	if (!fgets(output, sizeof(output), fp)) {
		fprintf(stderr, RED "check_allowed_functions: no output from is_cheating.sh\n");
		pclose(fp);
		exit(EXIT_FAILURE);
	}

	if (strcmp(output, "\n") != 0) {
		printf(TAB "Allowed functions" FNTAB RED "KO" RESET "\n\n");
		printf("%s\n", output);
		pclose(fp);
		exit(EXIT_FAILURE);
	}
	
	printf(TAB "Allowed functions" FNTAB GREEN "OK" RESET "\n");
}

void blank(void) {
	fprintf(stderr, RED "This chapter is not yet supported\n" RESET);
	exit(EXIT_FAILURE);
}

void check(void) {
	DIR *dp = opendir("ex0");
	if (!dp) {
		fprintf(stderr, RED "check: ex0: %s\n" RESET, strerror(errno));
		exit(EXIT_FAILURE);
	}

	int i;
	int ref_amt = 7;
	char* refs[] = {
		"ft_ft.c",
		"ft_str_is_alpha.c",
		"ft_foreach.c",
		"ft_strdup.c",
		"ft_print_program_name.c",
		"ft_strcpy.c",
		"ft_point.h",
	};
	void (*funcs[])(void) = {
		check_c_pointers,
		check_c_simple_strings,
		check_c_function_pointers,
		check_c_memory_management,
		blank,
		check_c_strings,
		check_c_structures,
	};
	struct dirent* entry;
	while ((entry = readdir(dp))) {
		i = 0;
		while (i < ref_amt) {
			if (strcmp(entry->d_name, refs[i]) == 0) {
				funcs[i]();
				printf(BOLD "Project status: " GREEN BOLD "Success\n" RESET);
				closedir(dp);
				return;
			}
			++i;
		}
	}
	closedir(dp);
	fprintf(stderr, RED "Couldn't determine the project\n" RESET);
	exit(EXIT_FAILURE);
}

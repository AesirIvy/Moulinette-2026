#include <errno.h>
#include <libgen.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "mostima.h"

char* get_self_path(void) {
	char buf[PATH_MAX];
	ssize_t len = readlink("/proc/self/exe", buf, sizeof(buf) - 1);
	if (len == -1) {
		fprintf(stderr, RED "get_cwd: readlink /proc/self/exe: %s\n" RESET, strerror(errno));
		exit(EXIT_FAILURE);
	}
	buf[len] = '\0';
	char* dir = dirname(buf);
	return dir;
}

void test_func(const char* dir, const char* test_path) {
	char tmp[TMP_SIZE];
	char hdr[BUF_SIZE];
	char cmd[OUT_SIZE];
	snprintf(hdr, sizeof(hdr), "-I %s/res/test -I '%s/%s' -I %s", get_self_path(), test_path, dir, dir);
	snprintf(cmd, sizeof(cmd), "cp '%s/%s/main.c' %s", test_path, dir, dir);
	if (system(cmd) != 0) {
		printf(TAB RED "test_func: system cp failed" RESET "\n\n");
		exit(EXIT_FAILURE);
	}
	
	snprintf(tmp, sizeof(tmp), "%s/main.c", dir);
	snprintf(cmd, sizeof(cmd), "cc -Wall -Wextra -Werror %s  %s/" "*.c >log.txt 2>&1", hdr, dir);
	if (system(cmd) != 0) {
		printf(TAB RED "Compilation failed" RESET "\n\n");
		FILE *fp = fopen("log.txt", "r");
		if (!fp) {
			fprintf(stderr, RED "test_func: fopen log.txt: %s\n" RESET, strerror(errno));
			exit(EXIT_FAILURE);
		}
		char line[BUF_SIZE];
		while (fgets(line, sizeof(line), fp))
			fputs(line, stderr);
		fclose(fp);
		remove(tmp);
		remove("log.txt");
		exit(EXIT_FAILURE);
	}
	remove(tmp);
	remove("log.txt");
	if (system("./a.out") != 0) {
		remove("a.out");
		printf(BOLD "Project status: " RED BOLD "failed\n" RESET);
		exit(EXIT_FAILURE);
	}
	remove("a.out");
}

static char *read_file(const char *path) {
	FILE *fp = fopen(path, "r");
	if (!fp) return NULL;

	fseek(fp, 0, SEEK_END);
	long size = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	char *content = malloc(size + 1);
	if (!content) {
		fclose(fp);
		return NULL;
	}
	fread(content, 1, size, fp);
	content[size] = '\0';
	fclose(fp);
	return content;
}

static void compare_output(const char *label, const char *expected, const char *actual, const char *dir) {
	if (expected == NULL)
		return;
	if (strcmp(expected, actual) != 0) {
		printf(TAB RED "Mismatch in %s for %s" RESET "\n\n", label, dir);
		printf("Expected:\n%s\n", expected);
		printf("Got:\n%s\n\n", actual);
		exit(EXIT_FAILURE);
	}
}

void test_prog(const char *dir, const char *args, const char *expected_stdout, const char *expected_stderr) {
	char cmd[OUT_SIZE];
	const char *out_std = "stdout.txt";
	const char *out_err = "stderr.txt";
	const char *log_file = "log.txt";
	const char *exe = "a.out";

	snprintf(cmd, sizeof(cmd), "cc -Wall -Wextra -Werror %s/*.c -o %s 2>%s", dir, exe, log_file);
	if (system(cmd) != 0) {
		fprintf(stderr, "Compilation failed for %s\n", dir);
		FILE *fp = fopen(log_file, "r");
		if (fp) {
			char line[BUF_SIZE];
			while (fgets(line, sizeof(line), fp))
				fputs(line, stderr);
			fclose(fp);
		}
		remove(log_file);
		exit(EXIT_FAILURE);
	}
	remove(log_file);

	if (args && args[0])
		snprintf(cmd, sizeof(cmd), "./%s %s >%s 2>%s", exe, args, out_std, out_err);
	else
		snprintf(cmd, sizeof(cmd), "./%s >%s 2>%s", exe, out_std, out_err);

	int ret = system(cmd);
	if (ret != 0) {
		fprintf(stderr, "Runtime error (exit %d) for %s\n", ret, dir);
		char *err_content = read_file(out_err);
		if (err_content) {
			fputs(err_content, stderr);
			free(err_content);
		}
		remove(out_std);
		remove(out_err);
		remove(exe);
		exit(EXIT_FAILURE);
	}

	char *stdout_content = read_file(out_std);
	char *stderr_content = read_file(out_err);

	remove(out_std);
	remove(out_err);
	remove(exe);

	if (!stdout_content || !stderr_content) {
		fprintf(stderr, "Failed to read output files for %s\n", dir);
		free(stdout_content);
		free(stderr_content);
		exit(EXIT_FAILURE);
	}

	compare_output("stdout", expected_stdout, stdout_content, dir);
	compare_output("stderr", expected_stderr, stderr_content, dir);

	free(stdout_content);
	free(stderr_content);
}

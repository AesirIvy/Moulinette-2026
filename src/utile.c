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

void test_func(char* dir, char* test_path) {
	char hdr[BUF_SIZE];
	char cmd[OUT_SIZE];
	snprintf(hdr, sizeof(hdr), "-I %s/res/test -I %s", get_self_path(), dir);
	snprintf(cmd, sizeof(cmd), "cc -Wall -Wextra -Werror %s %s/" "*.c '%s/%s/main.c' >log.txt 2>&1", hdr, dir, test_path, dir);
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
		remove("log.txt");
		exit(EXIT_FAILURE);
	}
	remove("log.txt");
	if (system("./a.out") != 0) {
		remove("a.out");
		printf(BOLD "Project status: " RED BOLD "failed\n" RESET);
		exit(EXIT_FAILURE);
	}
	remove("a.out");
}

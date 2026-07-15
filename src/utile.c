#include <errno.h>
#include <libgen.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "mostima.h"

char* get_cwd(void) {
	char buf[PATH_MAX];
	ssize_t len = readlink("/proc/self/exe", buf, sizeof(buf) - 1);
	if (len == -1) {
		fprintf(stderr, RED "/proc/self/exe\n: %s" RESET, strerror(errno));
		exit(EXIT_FAILURE);
	}
	buf[len] = '\0';
	char* dir = dirname(buf);
	return dir;
}

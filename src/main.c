#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "mostima.h"

int main(int argc, char** argv) {
	if (argc < 2) {
		print_help();
		return 0;
	}
	if (strcmp(argv[1], "check") == 0)
		check();
	else if (strcmp(argv[1], "help") == 0)
		print_help();
	else if (strcmp(argv[1], "report") == 0) {
		if (argc >= 2)
			print_report(argv[2]);
		else
			print_report(NULL);
	}
	else {
		fprintf(stderr, RED "%s is not a valid command" RESET "\n", argv[1]);
		print_help();
		return 1;
	}
	return 0;
}

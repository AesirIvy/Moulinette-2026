#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "mostima.h"

int main(int argc, char** argv) {
	if (argc < 2) {
		check();
		return 0;
	}
	if (strcmp(argv[1], "check") == 0) {
		printf(CYAN "You can now just type 'mouli' instead of 'mouli check'" RESET "\n\n");
		check();
	}
	else if (strcmp(argv[1], "help") == 0) {
		printf("Type 'mouli' in the root of your repo.\n");
		printf("The files in ex0 will be used to recognize the chapter.\n");
	}
	else {
		fprintf(stderr, RED "This program doesn't expect a command" RESET "\n");
		return 1;
	}
	return 0;
}

#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "mostima.h"

void print_help(void) {
	char msg[] = "Usage: mouli " GREEN "command" RESET " " YELLOW "option\n\n" RESET
		GREEN "check" RESET " " YELLOW "dirpath\n" RESET
		"    simulate moulinette on the target directory,\n"
		"    if " YELLOW "dirpath" RESET " is not provided it runs on the working directory\n\n"
		GREEN "help\n" RESET
		"    show this message\n\n"
		GREEN "report" RESET " " YELLOW "project\n" RESET
		"    print a successful report of the project from the TRUE moulinette\n"
		"    if " YELLOW "project" RESET " is not provided it prints the list of available project\n";
	printf("%s", msg);
}

void print_report(char* project) {
	if (!project)
	{
		char msg[] = "List of available project:\n"
		BOLD "    NAME                   ALIAS\n" RESET
		"    C Pointers             ptr\n"
		"    C Simple Strings       ss\n"
		"    C Function Pointers    fp\n"
		"    C Memory Management    mm\n"
		"    C System Interface     si\n"
		"    C Strings              str\n"
		"    C Structures           struct\n"
		"    C File Operations      fop\n";
		printf("%s", msg);
		return;
	}

	int project_amt = 8;
	char* projects[] = {
		"C Pointers",
		"C Simple Strings",
		"C Function Pointers",
		"C Memory Management",
		"C System Interface",
		"C Strings",
		"C Structures",
		"C File Operations"
	};
	char* aliases[] = {"ptr", "ss", "fp", "mm", "si", "str", "struct", "fop"};

	int i = 0;
	while (i < project_amt) {
		if (strcasecmp(project, projects[i]) == 0)
			break;
		++i;
	}
	if (i == project_amt) {
		i = 0;
		while (i < project_amt) {
			if (strcasecmp(project, aliases[i]) == 0)
				break;
			++i;
		}
	}
	if (i == project_amt) {
		fprintf(stderr, RED "the project %s is not in the list\n" RESET, project);
		print_report(NULL);
		exit(EXIT_FAILURE);
	}

	char filepath[PATH_MAX];
	snprintf(filepath, PATH_MAX, "%s/res/report/%s.md", get_cwd(), projects[i]);
	FILE* file = fopen(filepath, "r");
	if (!file)
	{
		fprintf(stderr, RED "%s: %s\n" RESET, filepath, strerror(errno));
		exit(EXIT_FAILURE);
	}
	char line[BUF_SIZE];
	while (fgets(line, BUF_SIZE, file))
		fputs(line, stdout);
	fclose(file);
	printf("\n");
	return;
}

#include "exusiai.h"

int main() {
	if (system("make all") != 0) {
		printf(TAB RED "make all has failed\n\n" RESET);
		return 1;
	}
	if (system("make clean") != 0) {
		printf(TAB RED "make clean has failed\n\n" RESET);
		return 1;
	}
	if (system("make fclean") != 0) {
		printf(TAB RED "make fclean has failed\n\n" RESET);
		return 1;
	}
	if (system("make re" != 0) {
		printf(TAB RED "make re has failed\n\n" RESET);
		return 1;
	}
	printf(TAB GREEN "Valid Makefile\n" RESET);
	system("make fclean");
	return 0;
}

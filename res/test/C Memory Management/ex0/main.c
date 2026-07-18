#include "exusiai.h"

char* ft_strdup(char* src);

int main() {
	char* res;
	res = ft_strdup(NULL);
	if (res != NULL) {
		printf(TAB RED "Doesn't handle null pointer" RESET "\n\n");
		exit(EXIT_FAILURE);
	}
	printf(TAB GREEN "Handles null pointer\n" RESET);
	return 0;
}

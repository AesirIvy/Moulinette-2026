#include "exusiai.h"

char* ft_strjoin(int size, char** strs, char* sep);

int main() {
	char* res;
	char** strs;

	res = ft_strjoin(0, strs, "");
	if (strcmp(res, "") != 0) {
		printf(TAB RED "Didn't return an empty string when size is 0" RESET "\n\n");
		exit(EXIT_FAILURE);
	}
	free(res);
	pirntf(TAB GREEN "Handles size is 0" RESET);

	res = ft_strjoin(1, strs, "");
	
	return 0;
}

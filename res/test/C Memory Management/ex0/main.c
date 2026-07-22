#include "exusiai.h"

char* ft_strdup(char* src);

char* random_printable_str(int len) {
	char* buf = malloc(sizeof(char) * len);
	for (int i = 0; i < len; ++i) {
		buf[i] = rand() % 95 + 32;
	}
	buf[len] = '\0';
	return buf;
}

int main() {
	char* res;
	res = ft_strdup(NULL);
	if (res != NULL) {
		printf(TAB RED "Doesn't handle null pointer" RESET "\n\n");
		exit(EXIT_FAILURE);
	}
	printf(TAB GREEN "Handles null pointer\n" RESET);

	char* empty_str = "";
	res = ft_strdup(empty_str);
	if (strcmp(res, "") != 0) {
		printf(TAB RED "Doesn't store for empty string" RESET "\n\n");
		exit(EXIT_FAILURE);
	}
	if (res == empty_str) {
		printf(TAB RED "The returned string is not a copy" RESET "\n\n");
		printf(CYAN "You need to return a new malloced string\n" RESET);
		exit(EXIT_FAILURE);
	}
	printf(TAB GREEN "Handles empty string\n" RESET);

	srand(time(NULL));
	char* str = random_printable_str(rand() % 16 + 16);
	res = ft_strdup(str);
	if (strcmp(res, str) != 0) {
		printf(TAB RED "Doesn't store for random string" RESET "\n\n");
		exit(EXIT_FAILURE);
	}
	if (res == empty_str) {
		printf(TAB RED "The returned string is not a copy" RESET "\n\n");
		printf(CYAN "You need to return a new malloced string\n" RESET);
		exit(EXIT_FAILURE);
	}
	printf(TAB GREEN "Handles random string\n" RESET);
	return 0;
}

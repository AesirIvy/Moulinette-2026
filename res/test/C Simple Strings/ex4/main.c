#include "exusiai.h"

int ft_str_is_printable(char* str);

char* random_non_printable_string(size_t len) {
	char* str = malloc(len + 1);
	if (str == NULL) {
		return NULL;
	}
	for (size_t i = 0; i < len; ++i) {
		str[i] = (char)(rand() % 32);
	}
	str[len] = '\0';
	return str;
}

int main() {
	if (ft_str_is_printable("") != 1) {
		printf(TAB RED "Doesn't handle empty string\n" RESET);
		return 1;
	}
	printf(TAB GREEN "Handles empty string\n" RESET);

	char printable[96];
	int i = 0;
	while (i < 95) {
		printable[i] = i + 32;
		++i;
	}
	printable[i] = '\0';
	if (ft_str_is_printable(printable) != 1) {
		printf(TAB RED "Doesn't handle string that contains only printable\n" RESET);
		return 1;
	}
	printf(TAB GREEN "Handles string that contains only printable\n" RESET);

	char non_printable[128];
	strcat(non_printable, printable);
	strcat(non_printable, random_non_printable_string(6));
	if (ft_str_is_printable(non_printable) != 0) {
		printf(TAB RED "Doesn't handle string that contains non printable\n" RESET);
		return 1;
	}
	printf(TAB GREEN "Handles string that contains non printable\n" RESET);
	return 0;
}

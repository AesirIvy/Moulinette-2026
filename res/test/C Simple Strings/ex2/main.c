#include "exusiai.h"

int ft_str_is_lowercase(char* str);

char* random_printable_string(size_t len) {
	char* str = malloc(len + 1);
	if (str == NULL) {
		return NULL;
	}
	for (size_t i = 0; i < len; ++i) {
		str[i] = (char)(rand() % (127 - 32) + 32);
	}
	str[len] = '\0';
	return str;
}

int main() {
	if (ft_str_is_lowercase("") != 1) {
		printf(TAB RED "Doesn't handle empty string\n" RESET);
		return 1;
	}
	printf(TAB GREEN "Handles empty string\n" RESET);

	char lower[] = "abcdefghijklmnopqrstuvwxyz";
	if (ft_str_is_lowercase(lower) != 1) {
		printf(TAB RED "Doesn't handle string that contains only lowercase\n" RESET);
		return 1;
	}
	printf(TAB GREEN "Handles string that contains only lowercase\n" RESET);

	char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	if (ft_str_is_lowercase(alpha) != 0) {
		printf(TAB RED "Doesn't handle string that contains only alpha\n" RESET);
		return 1;
	}
	printf(TAB GREEN "Handles string that contains only alpha\n" RESET);

	char non_alpha[64];
	strcat(non_alpha, alpha);
	strcat(non_alpha, random_printable_string(12));
	strcat(non_alpha, "Ø");
	if (ft_str_is_lowercase(non_alpha) != 0) {
		printf(TAB RED "Doesn't handle string that contains non alpha\n" RESET);
		return 1;
	}
	printf(TAB GREEN "Handles string that contains non alpha\n" RESET);
	return 0;
}

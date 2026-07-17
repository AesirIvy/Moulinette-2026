#include "exusiai.h"

int ft_str_is_numeric(char* str);

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
	if (ft_str_is_numeric("") != 1) {
		printf(TAB RED "Doesn't handle empty string\n" RESET);
		return 1;
	}
	printf(TAB GREEN "Handles empty string\n" RESET);

	char num[] = "0123456789";
	if (ft_str_is_numeric(num) != 1) {
		printf(TAB RED "Doesn't handle string that contains only numeric\n" RESET);
		return 1;
	}
	printf(TAB GREEN "Handles string that contains only numeric\n" RESET);

	char non_num[64];
	strcat(non_num, num);
	strcat(non_num, random_printable_string(12));
	strcat(non_num, "Ø");
	if (ft_str_is_numeric(non_num) != 0) {
		printf(TAB RED "Doesn't handle string that contains non numeric\n" RESET);
		return 1;
	}
	printf(TAB GREEN "Handles string that contains non numeric\n" RESET);
	return 0;
}

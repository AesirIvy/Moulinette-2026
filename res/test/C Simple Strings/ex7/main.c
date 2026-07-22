#include <ctype.h>
#include "exusiai.h"

char* ft_strcapitalize(char* str);

void to_title(char* str) {
	if (str == NULL)
		return;
	int first_letter = 1;
	int i = 0;
	while (str[i] != '\0') {
		if (first_letter && str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		else if (!first_letter && str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		first_letter = 0;
		if (
			str[i] < '0' || (str[i] > '9' && str[i] < 'A')
			|| (str[i] > 'Z' && str[i] < 'a') || str[i] > 'z'
		)
			first_letter = 1;
		++i;
	}
}

char* random_string(size_t len) {
	char* str = malloc(len + 1);
	if (str == NULL) {
		return NULL;
	}
	srand(time(NULL));
	for (size_t i = 0; i < len; ++i) {
		str[i] = (char)(rand() % (126 - 14) + 14);
	}
	str[len] = '\0';
	return str;
}

int main() {
	if (strcmp(ft_strcapitalize(""), "") != 0) {
		printf(TAB RED "Doesn't handle empty string\n\n" RESET);
		return 1;
	}
	printf(TAB GREEN "Handles empty string\n" RESET);

	char* str = random_string(64);
	char* res_str = strdup(str);
	to_title(res_str);
	if (strcmp(ft_strcapitalize(str), res_str) != 0) {
		printf(TAB RED "Failed to convert random string to title case\n\n" RESET);
		printf("Expected: %s\n", res_str);
		printf("Get: %s\n\n", str);
		return 1;
	}
	printf(TAB GREEN "Random string successfully converted to title case\n" RESET);

	free(res_str);
	free(str);
	return 0;
}

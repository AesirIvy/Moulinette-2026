#include <ctype.h>
#include "exusiai.h"

char* ft_strupcase(char* str);

void to_upper(char *str) {
	while (*str) {
		*str = toupper(*str);
		++str;
	}
}

char* random_non_printable_string(size_t len) {
	char* str = malloc(len + 1);
	if (str == NULL) {
		return NULL;
	}
	srand(time(NULL));
	for (size_t i = 0; i < len; ++i) {
		str[i] = (char)(rand() % 32);
	}
	str[len] = '\0';
	return str;
}

char* random_alpha_string(size_t len) {
	char* str = malloc(len + 1);
	if (str == NULL) {
		return NULL;
	}
	srand(time(NULL));
	for (size_t i = 0; i < len; ++i) {
		str[i] = (char)(rand() % (91 - 65) + 65);
		if (rand() % 2)
			str[i] += 32;
	}
	str[len] = '\0';
	return str;
}

int main() {
	if (strcmp(ft_strupcase(""), "") != 0) {
		printf(TAB RED "Doesn't handle empty string\n" RESET);
		return 1;
	}
	printf(TAB GREEN "Handles empty string\n" RESET);

	char* alpha = random_alpha_string(64);
	char* res_alpha = strdup(alpha);
	to_upper(res_alpha);
	if (strcmp(ft_strupcase(alpha), res_alpha) != 0) {
		printf(TAB RED "Failed to convert alpha only string to uppercase\n" RESET);
		return 1;
	}
	printf(TAB GREEN "Convertion successful on alpha only string\n" RESET);

	char non_printable[128];
	strcat(non_printable, alpha);
	strcat(non_printable, random_non_printable_string(6));
	char* res_non_printable = strdup(non_printable);
	to_upper(res_non_printable);
	if (strcmp(ft_strupcase(non_printable), res_non_printable) != 0) {
		printf(TAB RED "Failed to convert random string to uppercase\n" RESET);
		return 1;
	}
	printf(TAB GREEN "Convertion successful on non alpha string\n" RESET);
	free(res_non_printable);
	free(res_alpha);
	free(alpha);
	return 0;
}

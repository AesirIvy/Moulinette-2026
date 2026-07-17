#include "exusiai.h"

int ft_strlen(char* str);

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
	if (ft_strlen("") != 0) {
		printf(TAB RED "Doesn't handle empty string\n" RESET);
		return 1;
	}
	printf(TAB GREEN "Handles empty string\n" RESET);

	char* str = random_string(64);
	int out = ft_strlen(str);
	int res = strlen(str);
	if (out != res) {
		printf(TAB RED "Incorrect length value\n\n" RESET);
		printf("For: %s\n", str);
		printf("Expected: %d\n", res);
		printf("Get: %d\n", out);
		return 1;
	}
	printf(TAB GREEN "Correct length value\n" RESET);

	free(str);
	return 0;
}

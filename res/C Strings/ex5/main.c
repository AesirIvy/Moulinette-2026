#include "exusiai.h"

char *ft_strncat(char *dest, char *src, unsigned int nb);

char* random_word(int min_len, int max_len) {
	char consonants[] = "bcdfghjklmnpqrstvwxyz";
	char vowels[] = "aeiou";

	srand(time(NULL));
	int syllables = rand() % (max_len - min_len) + min_len;
	int length = syllables * 2 + 1;
	char* word = (char*)malloc(sizeof(char) * length);
	if (word == NULL)
		return NULL;
	for (int i = 0; i < syllables; ++i) {
		word[2 * i]  = consonants[rand() % (sizeof(consonants) - 1)];
		word[2 * i + 1] = vowels[rand() % (sizeof(vowels) - 1)];
	}
	word[length - 1] = '\0';
	return word;
}

int main() {
	char* str = random_word(3, 6);
	char* dst = (char*)malloc(sizeof(char) * 32);
	char* out = ft_strncat(dst, str, 32);
	if (strcmp(out, str) == 0)
		printf(TAB GREEN "Handles empty dest\n" RESET);
	else {
		printf(TAB RED "Doesn't handle empty dest\n\n" RESET);
		printf("Expecting: %s\n", str);
		printf("Get: %s\n\n", out);
		return 1;
	}

	char empty_src[] = "";
	out = ft_strncat(dst, empty_src, 32);
	if (strcmp(out, dst) == 0)
		printf(TAB GREEN "Handles empty src\n" RESET);
	else {
		printf(TAB RED "Doesn't handle empty src\n\n" RESET);
		printf("Expecting: %s\n", dst);
		printf("Get: %s\n\n", out);
		return 1;
	}

	char* src = (char*)malloc(sizeof(char) * 32);
	strcat(src, random_word(3, 8));

	out = ft_strncat(dst, src, 0);
	char* res_out = strncat(dst, src, 0);
	if (strcmp(out, res_out) == 0)
		printf(TAB GREEN "Handles n is 0\n" RESET);
	else {
		printf(TAB RED "Doesn't handle n is 0\n\n" RESET);
		printf("Expecting: %s\n", res_out);
		printf("Get: %s\n\n", out);
		return 1;
	}

	int n = strlen(src) * 2;
	out = ft_strncat(dst, src, n);
	res_out = strncat(dst, src, n);
	if (strcmp(out, res_out) == 0)
		printf(TAB GREEN "Handles n is larger than src\n" RESET);
	else {
		printf(TAB RED "Doesn't handle n is larger than src\n\n" RESET);
		printf("Expecting: %s\n", res_out);
		printf("Get: %s\n\n", out);
		return 1;
	}

	n = strlen(src) / 2;
	out = ft_strncat(dst, src, n);
	res_out = strncat(dst, src, n);
	if (strcmp(out, res_out) == 0)
		printf(TAB GREEN "Handles n is smaller than src\n" RESET);
	else {
		printf(TAB RED "Doesn't handle n is smaller than src\n\n" RESET);
		printf("Expecting: %s\n", res_out);
		printf("Get: %s\n\n", out);
		return 1;
	}
	free(str);
	free(src);
	free(dst);
	return 0;
}

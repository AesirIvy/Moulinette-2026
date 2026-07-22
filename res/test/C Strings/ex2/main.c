#include "exusiai.h"

int ft_strcmp(char *dest, char *src);

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
	char empty_s1[] = "";
	char empty_s2[] = "";
	int out = ft_strcmp(empty_s1, empty_s2);
	if (out == 0)
		printf(TAB GREEN "Handles empty string\n" RESET);
	else {
		printf(TAB RED "Doesn't handle empty string\n\n" RESET);
		printf("Expecting: %d\n", 0);
		printf("Get: %d\n\n", out);
		return 1;
	}

	char* str = random_word(3, 8);
	out = ft_strcmp(str, str);
	if (out == 0)
		printf(TAB GREEN "Handles same string\n" RESET);
	else {
		printf(TAB RED "Doesn't handle same string\n\n" RESET);
		printf("Expecting: %d\n", 0);
		printf("Get: %d\n\n", out);
		return 1;
	}

	char* s1 = (char*)malloc(sizeof(char) * 32);
	char* s2 = (char*)malloc(sizeof(char) * 32);
	char* base = random_word(2, 4);
	strcat(s1, base);
	strcat(s1, random_word(3, 5));
	strcat(s2, base);
	strcat(s2, random_word(3, 5));
	out = ft_strcmp(s1, s2);
	int res_out = strcmp(s1, s2);
	if (out == res_out)
		printf(TAB GREEN "Handles same prefix\n" RESET);
	else {
		printf(TAB RED "Doesn't handle same prefix\n\n" RESET);
		printf("Expecting: %d\n", res_out);
		printf("Get: %d\n\n", out);
		return 1;
	}
	free(str);
	free(base);
	free(s2);
	free(s1);
	return 0;
}

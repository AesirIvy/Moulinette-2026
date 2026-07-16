#include "exusiai.h"

void ft_strncpy(char *dest, char *src, unsigned int n);

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
	char* dest = (char*)malloc(sizeof(char) * 32);
	char empty_src[] = "";
	ft_strncpy(dest, empty_src, 32);
	if (strcmp(dest, "") == 0)
		printf(TAB GREEN "Handles empty string\n" RESET);
	else {
		printf(TAB RED "Doesn't handle empty string\n\n" RESET);
		printf("Expecting: \n");
		printf("Get: %s\n\n", dest);
		return 1;
	}

	char* src = random_word(3, 8);
	ft_strncpy(dest, src, 64);
	if (strcmp(dest, src) == 0)
		printf(TAB GREEN "Handles n greater than src len\n" RESET);
	else {
		printf(TAB RED "Doesn't handle n greater than src len\n\n" RESET);
		printf("Expecting: %s\n", src);
		printf("Get: %s\n\n", dest);
		return 1;
	}

	char* res_dest = (char*)malloc(sizeof(char) * 32);
	srand(time(NULL));
	int n = random() % 16;
	ft_strncpy(dest, src, n);
	strncpy(res_dest, src, n);
	if (strcmp(dest, src) == 0)
		printf(TAB GREEN "Handles n lower than src len\n" RESET);
	else {
		printf(TAB RED "Doesn't handle n lower than src len\n\n" RESET);
		printf("for n = %d\n", n);
		printf("Expecting: %s\n", res_dest);
		printf("Get: %s\n\n", dest);
		return 1;
	}
	free(src);
	free(dest);
	return 0;
}

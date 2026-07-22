#include "exusiai.h"

char *ft_strstr(char *str, char *to_find);

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
	char* dst = (char*)malloc(sizeof(char) * 32);
	strcat(dst, random_word(3, 7));
	char* out = ft_strstr(dst, "");
	if (strcmp(out, dst) == 0)
		printf(TAB GREEN "Handles empty to_find\n" RESET);
	else {
		printf(TAB RED "Doesn't handle empty to_find\n\n" RESET);
		printf("Expecting: %s\n", dst);
		printf("Get: %s\n\n", out);
		return 1;
	}

	out = ft_strstr(dst, "ø");
	if (out == NULL)
		printf(TAB GREEN "Handles to_find not found in str\n" RESET);
	else {
		printf(TAB RED "Doesn't handle to_find not found in str\n\n" RESET);
		printf("Expecting: NULL\n");
		printf("Get: %s\n\n", out);
		return 1;
	}

	out = ft_strstr(dst, &dst[0]);
	if (strcmp(out, dst) == 0)
		printf(TAB GREEN "Handles to_find occurs at the start of str\n" RESET);
	else {
		printf(TAB RED "Doesn't handle to_find occurs at the start of str\n\n" RESET);
		printf("Expecting: %s\n", dst);
		printf("Get: %s\n\n", out);
		return 1;
	}

	char middle = dst[strlen(dst) / 2];
	out = ft_strstr(dst, &middle);
	char* res_out = strstr(dst, &middle);
	if (strcmp(out, res_out) == 0)
		printf(TAB GREEN "Handles to_find occurs at the middle of str\n" RESET);
	else {
		printf(TAB RED "Doesn't handle to_find occurs at the middle of str\n\n" RESET);
		printf("Expecting: %s\n", res_out);
		printf("Get: %s\n\n", out);
		return 1;
	}

	strcat(dst, "end");
	out = ft_strstr(dst, "end");
	res_out = strstr(dst, "end");
	if (strcmp(out, res_out) == 0)
		printf(TAB GREEN "Handles to_find occurs at the end of str\n" RESET);
	else {
		printf(TAB RED "Doesn't handle to_find occurs at the end of str\n\n" RESET);
		printf("Expecting: %s\n", "end");
		printf("Get: %s\n\n", out);
		return 1;
	}

	strcat(dst, &middle);
	out = ft_strstr(dst, dst);
	res_out = strstr(dst, &middle);
	if (strcmp(out, res_out))
		printf(TAB GREEN "Handles to_find occurs occurs multiple times in str\n" RESET);
	else {
		printf(TAB RED "Doesn't handle to_find occurs multiple times in str\n\n" RESET);
		printf("Expecting: %s\n", res_out);
		printf("Get: %s\n\n", out);
		return 1;
	}
	free(dst);
	return 0;
}

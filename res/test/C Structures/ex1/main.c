#include "ft_stock_str.h"
#include "exusiai.h"

struct s_stock_str* ft_strs_to_tab(int ac, char** av);

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
	int ac = random() % 8 + 4;
	char** av = (char**)malloc(sizeof(char*) * ac);
	for (int i = 0; i < ac; ++i)
		av[i] = random_word(3, 5);
	t_stock_str* out = ft_strs_to_tab(ac, av);
	for (int i = 0; i < ac; ++i) {
		int res_size = strlen(av[i]);
		if (out[i].size != res_size) {
			printf(TAB RED "The stored size is incorrect\n\n" RESET);
			printf("Expecting: %d\n", res_size);
			printf("Get: %d\n\n", out[i].size);
			return 1;
		}
		if (strcmp(out[i].str, av[i]) != 0) {
			printf(TAB RED "The stored str is incorrect\n\n" RESET);
			printf("Expecting: %s\n", av[i]);
			printf("Get: %s\n\n", out[i].str);
			return 1;
		}
		if (out[i].str != av[i]) {
			printf(TAB RED "The stored str is a copy\n\n" RESET);
			printf("Expecting: address: %p\n", av[i]);
			printf("Get: address: %p\n\n", out[i].str);
			return 1;
		}
		if (strcmp(out[i].copy, av[i]) != 0) {
			printf(TAB RED "The stored copy is incorrect\n\n" RESET);
			printf("Expecting: %s\n", av[i]);
			printf("Get: %s\n\n", out[i].copy);
			return 1;
		}
		if (&out[i].copy == &av[i]) {
			printf(TAB RED "The stored copy received is the original\n\n" RESET);
			printf("Expecting: address: %p\n", av[i]);
			printf("Get: address: %p\n\n", out[i].copy);
			return 1;
		}
	}
	printf(TAB GREEN "Data are correctly stored\n" RESET);
	free(out);
	for (int i = 0; i < ac; ++i)
		free(av[i]);
	free(av);
	return 0;
}

#include "ft_stock_str.h"
#include "exusiai.h"

void ft_show_tab(struct s_stock_str* par);

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*tab;
	int			i;

	tab = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		tab[i].size = strlen(av[i]);
		tab[i].str = av[i];
		tab[i].copy = strdup(av[i]);
		if (!tab[i].copy)
		{
			while (i > 0)
			{
				free(tab[--i].copy);
			}
			free(tab);
			return (NULL);
		}
		++i;
	}
	tab[i].str = 0;
	return (tab);
}

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
	t_stock_str* tab = ft_strs_to_tab(ac, av);

	const char* tmp_file = "tmp.txt";
	freopen(tmp_file, "w", stdout);
	ft_show_tab(tab);
	fflush(stdout);
	freopen("/dev/tty", "w", stdout);

	FILE *fp = fopen(tmp_file, "r");
	if (!fp) {
		fprintf(stderr, "can't open the file");
		remove(tmp_file);
		exit(EXIT_FAILURE);
	}

	char line[BUF_SIZE];
	for (int i = 0; i < ac; ++i) {
		if (!fgets(line, sizeof(line), fp)) {
			printf(TAB RED "No line outputed for str" RESET);
			exit(EXIT_FAILURE);
		}
		line[strcspn(line, "\n")] = '\0';
		if (strcmp(line, tab[i].str) != 0) {
			printf(TAB RED "Incorrect str" RESET);
			printf("Expecting: %s\n", tab[i].str);
			printf("Get: %s\n", line);
			exit(EXIT_FAILURE);
		}

		if (!fgets(line, sizeof(line), fp)) {
			printf(TAB RED "No line outputed for size" RESET);
			exit(EXIT_FAILURE);
		}
		line[strcspn(line, "\n")] = '\0';
		int size;
		if (sscanf(line, "%d", &size) != 1 || size != tab[i].size) {
			printf(TAB RED "Incorrect size" RESET);
			printf("Expecting: %d\n", tab[i].size);
			printf("Get: %s\n", line);
		}


		if (!fgets(line, sizeof(line), fp)) {
			printf(TAB RED "No line outputed for copy" RESET);
			exit(EXIT_FAILURE);
		}
		line[strcspn(line, "\n")] = '\0';
		if (strcmp(line, tab[i].copy) != 0) {
			printf(TAB RED "Incorrect copy" RESET);
			printf("Expecting: %s\n", tab[i].copy);
			printf("Get: %s\n", line);
		}
	}
	printf(TAB GREEN "Values are correctly displayed\n" RESET);
	remove(tmp_file);
	free(tab);
	for (int i = 0; i < ac; ++i)
		free(av[i]);
	free(av);
	return 0;
}

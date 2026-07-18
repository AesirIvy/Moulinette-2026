#include "exusiai.h"

int ft_count_if(char** tab, int length, int (*f)(char*));

int secret_fn(char* str) {
	if (strcmp(str, "Lain"))
		return 0;
	return 1;
}

int main() {
	char* empty_tab[0];
	if (ft_count_if(empty_tab, 0, secret_fn) != 0) {
		printf(TAB RED "Doesn't handle empty tab" RESET "\n\n");
		exit(EXIT_FAILURE);
	}
	printf(TAB GREEN "Handles empty tab\n" RESET);

	srand(time(NULL));
	int size = random() % 10 + 10;
	char* tab[size];
	for (int i = 0; i < size; ++i)
		tab[i] = "Nial";
	if (ft_count_if(tab, size, secret_fn) != 0) {
		printf(TAB RED "Doesn't handle all false" RESET "\n\n");
		exit(EXIT_FAILURE);
	}
	printf(TAB GREEN "Handles empty all false\n" RESET);

	for (int i = 0; i < size; ++i)
		tab[i] = "Lain";
	if (ft_count_if(tab, size, secret_fn) != size) {
		printf(TAB RED "Doesn't handle all true\n" RESET);
		exit(EXIT_FAILURE);
	}
	printf(TAB GREEN "Handles empty all true\n" RESET);

	tab[0] = "Nial";
	tab[1] = "Lain";
	int lain_cnt = 1;
	for (int i = 2; i < size; ++i) {
		if (random() % 2 == 0) {
			tab[i] = "Lain";
			++lain_cnt;
		}
		else
			tab[i] = "Nial";
	}
	int out = ft_count_if(tab, size, secret_fn);
	if (out != lain_cnt) {
		printf(TAB RED "Doesn't handle mixed result" RESET "\n\n");
		printf("Expecting: %d\n", lain_cnt);
		printf("Get: %d\n", out);
		exit(EXIT_FAILURE);
	}
	printf(TAB GREEN "Handles empty mixed result\n" RESET);
	return 0;
}

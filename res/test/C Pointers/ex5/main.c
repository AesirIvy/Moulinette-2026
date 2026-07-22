#include "exusiai.h"

void ft_rev_int_tab(int *tab, int size);

int* intdup(int* src, int size) {
	if (!src || size <= 0)
		return NULL;
	int* dup = malloc(sizeof(int) * size);
	if (!dup)
		return NULL;
	for (int i = 0; i < size; ++i)
		dup[i] = src[i];
	return dup;
}

void rev_int_tab(int* tab, int size) {
	for (int i = 0; i < size / 2; ++i) {
		int tmp = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = tmp;
	}
}

int main() {
	int* empty_tab = NULL;
	ft_rev_int_tab(empty_tab, 0);
	if (!empty_tab)
		printf(TAB GREEN "Handles empty tab\n" RESET);
	else {
		printf(TAB RED "Doesn't handle empty tab\n\n" RESET);
		return 1;
	}

	srand(time(NULL));
	int size = rand() % 10 + 5;
	int* tab = (int*)malloc(sizeof(int) * size);
	for (int i = 0; i < size; ++i) {
		tab[i] = RAND_INT;
	}
	int* res_tab = intdup(tab, size);
	ft_rev_int_tab(tab, size);
	rev_int_tab(res_tab, size);
	for (int i = 0; i < size; ++i)
		if (tab[i] != res_tab[i]) {
			printf(TAB RED "Doesn't handle int array\n\n" RESET);
			printf("Expected:\n");
			for (int j = 0; j < size; ++j)
				printf(TAB "%d\n", res_tab[j]);
			printf("\n");
			printf("Get:\n");
			for (int j = 0; j < size; ++j)
				printf(TAB "%d\n", tab[j]);
			printf("\n");
			return 1;
		}
	printf(TAB GREEN "Handles int array\n" RESET);
	free(tab);
	free(res_tab);
	return 0;
}

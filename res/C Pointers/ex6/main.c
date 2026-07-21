#include "exusiai.h"

void ft_sort_int_tab(int *tab, int size);

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

int cmp_int_asc(const void *a, const void *b) {
	int ia = *(const int *)a;
	int ib = *(const int *)b;
	return (ia > ib) - (ia < ib);
}

int cmp_int_desc(const void *a, const void *b) {
	int ia = *(const int *)a;
	int ib = *(const int *)b;
	return (ia < ib) - (ia > ib);
}

int main() {
	int* empty_tab = NULL;
	ft_sort_int_tab(empty_tab, 0);
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
	ft_sort_int_tab(tab, size);
	qsort(res_tab, size, sizeof(int), cmp_int_asc);
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

	ft_sort_int_tab(tab, size);
	for (int i = 0; i < size; ++i)
		if (tab[i] != res_tab[i]) {
			printf(TAB RED "Doesn't handle sorted array\n\n" RESET);
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
	printf(TAB GREEN "Handles sorted array\n" RESET);

	qsort(tab, size, sizeof(int), cmp_int_desc);
	ft_sort_int_tab(tab, size);
	for (int i = 0; i < size; ++i)
		if (tab[i] != res_tab[i]) {
			printf(TAB RED "Doesn't handle reverse sorted array\n\n" RESET);
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
	printf(TAB GREEN "Handles reverse sorted array\n" RESET);
	free(tab);
	free(res_tab);
	return 0;
}

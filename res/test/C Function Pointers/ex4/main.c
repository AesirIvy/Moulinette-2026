#include "exusiai.h"

int ft_is_sort(int* tab, int length, int (*f)(int, int));

int secret_fn(int a, int b) {
	a %= 10;
	b %= 10;
	if (a < b)
		return -1;
	else if (a > b)
		return 1;
	else
		return 0;
}

int main() {
	int empty_tab[0];
	if (ft_is_sort(empty_tab, 0, secret_fn) != 1) {
		printf(TAB RED "Doesn't handle empty tab" RESET "\n\n");
		exit(EXIT_FAILURE);
	}
	printf(TAB GREEN "Handles empty tab\n" RESET);

	srand(time(NULL));
	int single_tab[1] = {RAND_INT};
	if (ft_is_sort(single_tab, 1, secret_fn) != 1) {
		printf(TAB RED "Doesn't handle empty tab" RESET "\n\n");
		exit(EXIT_FAILURE);
	}
	printf(TAB GREEN "Handles empty tab\n" RESET);

	int size = random() % 5 + 5;
	int asc_tab[size];
	for (int i = 0; i < size; ++i)
		asc_tab[i] = (random() % 100) * 10 + i;
	if (ft_is_sort(asc_tab, size, secret_fn) != 1) {
		printf(TAB RED "Doesn't handle sorted ascending" RESET "\n\n");
		exit(EXIT_FAILURE);
	}
	printf(TAB GREEN "Handles sorted ascending\n" RESET);

	int desc_tab[size];
	for (int i = size - 1; i >= 0; --i)
		desc_tab[i] = (random() % 100) * 10 + i;
	if (ft_is_sort(desc_tab, size, secret_fn) != 1) {
		printf(TAB RED "Doesn't handle sorted descending" RESET "\n\n");
		exit(EXIT_FAILURE);
	}
	printf(TAB GREEN "Handles sorted descending\n" RESET);

	int double_tab[size*2];
	for (int i = 0; i < size; ++i)
		double_tab[i] = asc_tab[i];
	for (int i = size; i < size * 2; ++i)
		double_tab[i] = desc_tab[i - size];
	if (ft_is_sort(double_tab, size * 2, secret_fn) != 0) {
		printf(TAB RED "Doesn't handle unsorted array\n" RESET);
		exit(EXIT_FAILURE);
	}
	printf(TAB GREEN "Handles unsorted array\n" RESET);

	int tab[size];
	int n = RAND_INT;
	for (int i = 0; i < size; ++i)
		tab[i] = n;
	if (ft_is_sort(tab, size, secret_fn) != 1) {
		printf(TAB RED "Doesn't handle all equal" RESET "\n\n");
		exit(EXIT_FAILURE);
	}
	printf(TAB GREEN "Handles all equal\n" RESET);
	return 0;
}

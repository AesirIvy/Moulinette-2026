#include "exusiai.h"

int* ft_map(int* tab, int length, int (*f)(int));

int secret_fn(int val) {
	return val / 2;
}

int main() {
	srand(time(NULL));
	int size = random() % 10 + 10;
	int og_tab[size];
	int dup_tab[size];
	for (int i = 0; i < size; ++i) {
		int n = RAND_INT;
		og_tab[i] = n;
		dup_tab[i] = n;
	}
	int* out = ft_map(dup_tab, size, secret_fn);
	for (int i = 0; i < size; ++i) {
		if (out[i] != og_tab[i] / 2) {
			printf(TAB RED "Incorrect items in returned tab" RESET "\n\n");
			printf("For i = %d", i);
			printf("Expecting: %d", og_tab[i] / 2);
			printf("Get: %d\n\n", out[i]);
			exit(EXIT_FAILURE);
		}
	}
	printf(TAB GREEN "Handles mysterious function\n" RESET);
	free(out);
	return 0;
}

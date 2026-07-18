#include "exusiai.h"

int ft_any(char** tab, int (*f)(char*));

int secret_fn(char* str) {
	if (strcmp(str, "True"))
		return 0;
	return 1;
}

int main() {
	srand(time(NULL));
	int size = random() % 10 + 10;
	char* tab[size];
	tab[0] = NULL;
	if (ft_any(tab, secret_fn) != 0) {
		printf(TAB RED "Doesn't handle empty tab" RESET "\n\n");
		exit(EXIT_FAILURE);
	}
	printf(TAB GREEN "Handles empty tab\n" RESET);

	for (int i = 0; i < size - 1; ++i)
		tab[i] = "False";
	tab[size - 1] = NULL;
	if (ft_any(tab, secret_fn) != 0) {
		printf(TAB RED "Doesn't handle all false\n" RESET "\n\n");
		exit(EXIT_FAILURE);
	}
	printf(TAB GREEN "Handles empty all false\n" RESET);

	for (int i = 0; i < size - 1; ++i)
		tab[i] = "True";
	tab[size - 1] = NULL;
	if (ft_any(tab, secret_fn) != 1) {
		printf(TAB RED "Doesn't handle all true" RESET "\n\n");
		exit(EXIT_FAILURE);
	}
	printf(TAB GREEN "Handles empty all true\n" RESET);

	int true_pos = random() % (size - 1);
	for (int i = 0; i < size - 1; ++i) {
		if (i == true_pos)
			tab[i] = "True";
		else
			tab[i] = "False";
	}
	tab[size - 1] = NULL;
	if (ft_any(tab, secret_fn) != 1) {
		printf(TAB RED "Doesn't handle one true" RESET "\n\n");
		exit(EXIT_FAILURE);
	}
	printf(TAB GREEN "Handles empty one true\n" RESET);
	return 0;
}

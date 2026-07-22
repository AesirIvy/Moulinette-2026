#include "exusiai.h"

int* ft_range(int min, int max);

int main() {
	int min, max;
	int* res;
	srand(time(NULL));

	min = rand() % 20 - 10;
	max = min - rand() % 5 + 1;
	res = ft_range(min, max);
	if (res != NULL) {
		printf(TAB RED "Didn't return a null pointer when min > max" RESET "\n\n");
		exit(EXIT_FAILURE);
	}
	printf(TAB GREEN "Handles min > max\n" RESET);

	max = min;
	res = ft_range(min, max);
	if (res != NULL) {
		printf(TAB RED "Didn't return a null pointer when min = max" RESET "\n\n");
		exit(EXIT_FAILURE);
	}
	printf(TAB GREEN "Handles min = max\n" RESET);

	max = min + rand() % 5 + 1;
	res = ft_range(min, max);
	int i = 0;
	while (min < max) {
		if (res[i++] != min) {
			printf(TAB RED "Doesn't handle random range" RESET "\n\n");
			exit(EXIT_FAILURE);
		}
		++min;
	}
	printf(TAB GREEN "Handles random range\n" RESET);

	return 0;
}

#include "exusiai.h"

int ft_ultimate_range(int** range, int min, int max);

int main() {
	int min, max;
	int res;
	int* range;
	srand(time(NULL));

	min = rand() % 20 - 10;
	max = min - rand() % 5 + 1;
	res = ft_ultimate_range(&range, min, max);
	if (range != NULL) {
		printf(TAB RED "Didn't point range to NULL when min > max" RESET "\n\n");
		exit(EXIT_FAILURE);
	}
	if (res != 0) {
		printf(TAB RED "Didn't return 0 when min > max" RESET "\n\n");
		exit(EXIT_FAILURE);
	}
	printf(TAB GREEN "Handles min > max\n" RESET);

	max = min;
	res = ft_ultimate_range(&range, min, max);
	if (range != NULL) {
		printf(TAB RED "Didn't point range to NULL when min = max" RESET "\n\n");
		exit(EXIT_FAILURE);
	}
	if (res != 0) {
		printf(TAB RED "Didn't return 0 when min = max" RESET "\n\n");
		exit(EXIT_FAILURE);
	}
	printf(TAB GREEN "Handles min = max\n" RESET);

	max = min + rand() % 5 + 1;
	res = ft_ultimate_range(&range, min, max);
	int size = max - min;
	if (res != size) {
		printf(TAB RED "The returned range is incorrect" RESET "\n\n");
		printf("Expecting: %d\n", size);
		printf("Get: %d\n\n", res);
		exit(EXIT_FAILURE);
	}
	if (!range) {
		printf(TAB RED "The range is empty" RESET "\n\n");
		exit(EXIT_FAILURE);
	}
	int i = 0;
	while (min < max) {
		if (range[i++] != min) {
			printf(TAB RED "Doesn't handle random range" RESET "\n\n");
			exit(EXIT_FAILURE);
		}
		++min;
	}
	printf(TAB GREEN "Handles random range\n" RESET);

	return 0;
}

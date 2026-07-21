#include "exusiai.h"

void ft_swap(int *a, int *b);

int main() {
	srand(time(NULL));
	int a = RAND_INT;
	int b = RAND_INT;
	int res_a = b;
	int res_b = a;
	ft_swap(&a, &b);
	if (a == res_a && b == res_b)
		printf(TAB GREEN "Swap successful\n" RESET);
	else {
		printf(TAB RED "Swap unsuccessful\n\n" RESET);
		printf("Input:\n" TAB "a = %d\n" TAB "b = %d\n\n", res_b, res_a);
		printf("Expecting:\n" TAB "a = %d\n" TAB "b = %d\n\n", res_a, res_b);
		printf("Get:\n" TAB "a = %d\n" TAB "b = %d\n\n", a, b);
		return 1;
	}
	return 0;
}

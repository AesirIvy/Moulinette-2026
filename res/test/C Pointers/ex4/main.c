#include "exusiai.h"

void ft_ultimate_div_mod(int *a, int *b);

int main() {
	srand(time(NULL));
	int a = RAND_INT;
	int b = RAND_INT;
	if (b == 0)
		b = 1;
	int res_a = a / b;
	int res_b = a % b;
	ft_ultimate_div_mod(&a, &b);
	if (a == res_a && b == res_b)
		printf(TAB GREEN "Operation successful\n" RESET);
	else {
		printf(TAB RED "Operation unsuccesful\n\n" RESET);
		printf("Input:\n" TAB "a = %d\n" TAB "b = %d\n\n", a, b);
		printf("Expecting:\n" TAB "div = %d\n" TAB "mod = %d\n\n", res_a, res_b);
		printf("Get:\n" TAB "div = %d\n" TAB "mod = %d\n\n", a, b);
		return 1;
	}
	return 0;
}

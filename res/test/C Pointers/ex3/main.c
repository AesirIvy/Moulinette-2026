#include "exusiai.h"

void ft_div_mod(int a, int b, int *div, int *mod);

int main() {
	srand(time(NULL));
	int a = RAND_INT;
	int b = RAND_INT;
	if (b == 0)
		b = 1;
	int div;
	int mod;
	ft_div_mod(a, b, &div, &mod);
	if (div == a / b && mod == a % b)
		printf(TAB GREEN "Operation successful\n" RESET);
	else {
		printf(TAB RED "Operation unsuccesful\n\n" RESET);
		printf("Input:\n" TAB "a = %d\n" TAB "b = %d\n\n", a, b);
		printf("Expecting:\n" TAB "div = %d\n" TAB "mod = %d\n\n", a / b, a % b);
		printf("Get:\n" TAB "div = %d\n" TAB "mod = %d\n\n", div, mod);
		return 1;
	}
	return 0;
}

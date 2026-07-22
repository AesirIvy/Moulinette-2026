#include "exusiai.h"

void ft_ultimate_ft(int *********nbr);

int main() {
	int nbr;
	ft_ultimate_ft(
		&(int********){&(int*******){&(int******){&(int*****){&(int****){&(int***){&(int**){&(int*){&nbr}}}}}}}}
	);
	if (nbr == 42)
		printf(TAB GREEN "Value 42 is stored\n" RESET);
	else {
		printf(TAB RED "Value 42 isn't stored\n\n" RESET);
		printf("Expecting: 42\n");
		printf("Get: %d\n\n", nbr);
		return 1;
	}
	return 0;
}

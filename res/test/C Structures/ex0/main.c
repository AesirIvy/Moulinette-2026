#include "ft_point.h"
#include "exusiai.h"

void set_point(t_point* point) {
	point->x = 42;
	point->y = 21;
}

int main() {
	t_point point;

	set_point(&point);
	if (point.x == 42 && point.y == 21)
		printf(TAB GREEN "Values are correctly stored in point\n" RESET);
	else {
		printf(TAB RED "Values aren't correctly stored in point\n\n" RESET);
		printf("Expecting:\n" TAB "x: 42\n" TAB "y: 21\n\n");
		printf("Get:\n" TAB "x: %d\n" TAB "y: %d\n\n", point.x, point.y);
		return 1;
	}
	return 0;
}

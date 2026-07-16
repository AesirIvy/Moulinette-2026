#include <stdio.h>
#include "mostima.h"

void check_c_pointers() {
	char test_path[TMP_SIZE];
	snprintf(test_path, sizeof(test_path), "%s/res/test/C Pointers", get_self_path());

	printf(BOLD "Exercise 0: ft_ft\n" RESET);
	char* ex0_expected[] = {"ft_ft.c", NULL};
	check_allowed_files("ex0", ex0_expected, NULL);
	check_norminette("ex0");
	check_allowed_functions("ex0", NULL);
	printf("\n");
	test_func("ex0", test_path);
	printf("\n");

	printf(BOLD "Exercise 1: ft_ultimate_ft\n" RESET);
	char* ex1_expected[] = {"ft_ultimate_ft.c", NULL};
	check_allowed_files("ex1", ex1_expected, NULL);
	check_norminette("ex1");
	check_allowed_functions("ex1", NULL);
	printf("\n");
	test_func("ex1", test_path);
	printf("\n");

	printf(BOLD "Exercise 2: ft_swap\n" RESET);
	char* ex2_expected[] = {"ft_swap.c", NULL};
	check_allowed_files("ex2", ex2_expected, NULL);
	check_norminette("ex2");
	check_allowed_functions("ex2", NULL);
	printf("\n");
	test_func("ex2", test_path);
	printf("\n");

	printf(BOLD "Exercise 3: ft_div_mod\n" RESET);
	char* ex3_expected[] = {"ft_div_mod.c", NULL};
	check_allowed_files("ex3", ex3_expected, NULL);
	check_norminette("ex3");
	check_allowed_functions("ex3", NULL);
	printf("\n");
	test_func("ex3", test_path);
	printf("\n");

	printf(BOLD "Exercise 4: ft_ultimate_div_mod\n" RESET);
	char* ex4_expected[] = {"ft_ultimate_div_mod.c", NULL};
	check_allowed_files("ex4", ex4_expected, NULL);
	check_norminette("ex4");
	check_allowed_functions("ex4", NULL);
	printf("\n");
	test_func("ex4", test_path);
	printf("\n");

	printf(BOLD "Exercise 5: ft_rev_int_tab\n" RESET);
	char* ex5_expected[] = {"ft_rev_int_tab.c", NULL};
	check_allowed_files("ex5", ex5_expected, NULL);
	check_norminette("ex5");
	check_allowed_functions("ex5", NULL);
	printf("\n");
	test_func("ex5", test_path);
	printf("\n");

	printf(BOLD "Exercise 6: ft_sort_int_tab\n" RESET);
	char* ex6_expected[] = {"ft_sort_int_tab.c", NULL};
	check_allowed_files("ex6", ex6_expected, NULL);
	check_norminette("ex6");
	check_allowed_functions("ex6", NULL);
	printf("\n");
	test_func("ex6", test_path);
	printf("\n");

	printf(BOLD "Status: " GREEN BOLD "Success\n" RESET);
}

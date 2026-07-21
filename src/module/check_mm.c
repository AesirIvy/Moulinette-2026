#include "mostima.h"

void check_c_pointers(void) {
	char test_path[TMP_SIZE];
	snprintf(test_path, sizeof(test_path), "%s/res/C Pointers", get_self_path());

	printf(BOLD "Exercise 0: ft_ft\n" RESET);
	char* ex0_expected[] = {"ft_ft.c", NULL};
	check_allowed_files("ex0", ex0_expected, NULL);
	check_norminette("ex0", "");
	check_allowed_functions("ex0", test_path, NULL);
	printf("\n");
	test_func("ex0", test_path);
	printf("\n");

	printf(BOLD "Exercise 1: ft_ultimate_ft\n" RESET);
	char* ex1_expected[] = {"ft_ultimate_ft.c", NULL};
	check_allowed_files("ex1", ex1_expected, NULL);
	check_norminette("ex1", "");
	check_allowed_functions("ex1", test_path, NULL);
	printf("\n");
	test_func("ex1", test_path);
	printf("\n");

	printf(BOLD "Exercise 2: ft_swap\n" RESET);
	char* ex2_expected[] = {"ft_swap.c", NULL};
	check_allowed_files("ex2", ex2_expected, NULL);
	check_norminette("ex2", "");
	check_allowed_functions("ex2", test_path, NULL);
	printf("\n");
	test_func("ex2", test_path);
	printf("\n");

	printf(BOLD "Exercise 3: ft_div_mod\n" RESET);
	char* ex3_expected[] = {"ft_div_mod.c", NULL};
	check_allowed_files("ex3", ex3_expected, NULL);
	check_norminette("ex3", "");
	check_allowed_functions("ex3", test_path, NULL);
	printf("\n");
	test_func("ex3", test_path);
	printf("\n");

	printf(BOLD "Exercise 4: ft_ultimate_div_mod\n" RESET);
	char* ex4_expected[] = {"ft_ultimate_div_mod.c", NULL};
	check_allowed_files("ex4", ex4_expected, NULL);
	check_norminette("ex4", "");
	check_allowed_functions("ex4", test_path, NULL);
	printf("\n");
	test_func("ex4", test_path);
	printf("\n");

	printf(BOLD "Exercise 5: ft_rev_int_tab\n" RESET);
	char* ex5_expected[] = {"ft_rev_int_tab.c", NULL};
	check_allowed_files("ex5", ex5_expected, NULL);
	check_norminette("ex5", "");
	check_allowed_functions("ex5", test_path, NULL);
	printf("\n");
	test_func("ex5", test_path);
	printf("\n");

	printf(BOLD "Exercise 6: ft_sort_int_tab\n" RESET);
	char* ex6_expected[] = {"ft_sort_int_tab.c", NULL};
	check_allowed_files("ex6", ex6_expected, NULL);
	check_norminette("ex6", "");
	check_allowed_functions("ex6", test_path, NULL);
	printf("\n");
	test_func("ex6", test_path);
	printf("\n");
}

void check_c_simple_strings(void) {
	char test_path[TMP_SIZE];
	snprintf(test_path, sizeof(test_path), "%s/res/C Simple Strings", get_self_path());

	printf(BOLD "Exercise 0: ft_str_is_alpha\n" RESET);
	char* ex0_expected[] = {"ft_str_is_alpha.c", NULL};
	check_allowed_files("ex0", ex0_expected, NULL);
	check_norminette("ex0", "");
	check_allowed_functions("ex0", test_path, NULL);
	printf("\n");
	test_func("ex0", test_path);
	printf("\n");

	printf(BOLD "Exercise 1: ft_str_is_numeric\n" RESET);
	char* ex1_expected[] = {"ft_str_is_numeric.c", NULL};
	check_allowed_files("ex1", ex1_expected, NULL);
	check_norminette("ex1", "");
	check_allowed_functions("ex1", test_path, NULL);
	printf("\n");
	test_func("ex1", test_path);
	printf("\n");

	printf(BOLD "Exercise 2: ft_str_is_lowercase\n" RESET);
	char* ex2_expected[] = {"ft_str_is_lowercase.c", NULL};
	check_allowed_files("ex2", ex2_expected, NULL);
	check_norminette("ex2", "");
	check_allowed_functions("ex2", test_path, NULL);
	printf("\n");
	test_func("ex2", test_path);
	printf("\n");

	printf(BOLD "Exercise 3: ft_str_is_uppercase\n" RESET);
	char* ex3_expected[] = {"ft_str_is_uppercase.c", NULL};
	check_allowed_files("ex3", ex3_expected, NULL);
	check_norminette("ex3", "");
	check_allowed_functions("ex3", test_path, NULL);
	printf("\n");
	test_func("ex3", test_path);
	printf("\n");

	printf(BOLD "Exercise 4: ft_str_is_printable\n" RESET);
	char* ex4_expected[] = {"ft_str_is_printable.c", NULL};
	check_allowed_files("ex4", ex4_expected, NULL);
	check_norminette("ex4", "");
	check_allowed_functions("ex4", test_path, NULL);
	printf("\n");
	test_func("ex4", test_path);
	printf("\n");

	printf(BOLD "Exercise 5: ft_strupcase\n" RESET);
	char* ex5_expected[] = {"ft_strupcase.c", NULL};
	check_allowed_files("ex5", ex5_expected, NULL);
	check_norminette("ex5", "");
	check_allowed_functions("ex5", test_path, NULL);
	printf("\n");
	test_func("ex5", test_path);
	printf("\n");

	printf(BOLD "Exercise 6: ft_strlowcase\n" RESET);
	char* ex6_expected[] = {"ft_strlowcase.c", NULL};
	check_allowed_files("ex6", ex6_expected, NULL);
	check_norminette("ex6", "");
	check_allowed_functions("ex6", test_path, NULL);
	printf("\n");
	test_func("ex6", test_path);
	printf("\n");

	printf(BOLD "Exercise 7: ft_strcapitalize\n" RESET);
	char* ex7_expected[] = {"ft_strcapitalize.c", NULL};
	check_allowed_files("ex7", ex7_expected, NULL);
	check_norminette("ex7", "");
	check_allowed_functions("ex7", test_path, NULL);
	printf("\n");
	test_func("ex7", test_path);
	printf("\n");

	printf(BOLD "Exercise 8: ft_strlen\n" RESET);
	char* ex8_expected[] = {"ft_strlen.c", NULL};
	check_allowed_files("ex8", ex8_expected, NULL);
	check_norminette("ex8", "");
	check_allowed_functions("ex8", test_path, NULL);
	printf("\n");
	test_func("ex8", test_path);
	printf("\n");

	printf(BOLD "Exercise 9: ft_putstr\n" RESET);
	char* ex9_expected[] = {"ft_putstr.c", NULL};
	char* ex9_allowed[] = {"write", NULL};
	check_allowed_files("ex9", ex9_expected, NULL);
	check_norminette("ex9", "");
	check_allowed_functions("ex9", test_path, ex9_allowed);
	printf("\n");
	test_func("ex9", test_path);
	printf("\n");

	printf(BOLD "Exercise 10: ft_putstr_non_printable\n" RESET);
	char* ex10_expected[] = {"ft_putstr_non_printable.c", NULL};
	char* ex10_allowed[] = {"write", NULL};
	check_allowed_files("ex10", ex10_expected, NULL);
	check_norminette("ex10", "");
	check_allowed_functions("ex10", test_path, ex10_allowed);
	printf("\n");
	test_func("ex10", test_path);
	printf("\n");
}

void check_c_function_pointers(void) {
	char test_path[TMP_SIZE];
	snprintf(test_path, sizeof(test_path), "%s/res/C Function Pointers", get_self_path());

	printf(BOLD "Exercise 0: ft_foreach\n" RESET);
	char* ex0_expected[] = {"ft_foreach.c", NULL};
	check_allowed_files("ex0", ex0_expected, NULL);
	check_norminette("ex0", "");
	check_allowed_functions("ex0", test_path, NULL);
	printf("\n");
	test_func("ex0", test_path);
	printf("\n");

	printf(BOLD "Exercise 1: ft_map\n" RESET);
	char* ex1_expected[] = {"ft_map.c", NULL};
	char* ex1_allowed[] = {"malloc", NULL};
	check_allowed_files("ex1", ex1_expected, NULL);
	check_norminette("ex1", "");
	check_allowed_functions("ex1", test_path, ex1_allowed);
	printf("\n");
	test_func("ex1", test_path);
	printf("\n");

	printf(BOLD "Exercise 2: ft_any\n" RESET);
	char* ex2_expected[] = {"ft_any.c", NULL};
	check_allowed_files("ex2", ex2_expected, NULL);
	check_norminette("ex2", "");
	check_allowed_functions("ex2", test_path, NULL);
	printf("\n");
	test_func("ex2", test_path);
	printf("\n");

	printf(BOLD "Exercise 3: ft_count_if\n" RESET);
	char* ex3_expected[] = {"ft_count_if.c", NULL};
	check_allowed_files("ex3", ex3_expected, NULL);
	check_norminette("ex3", "");
	check_allowed_functions("ex3", test_path, NULL);
	printf("\n");
	test_func("ex3", test_path);
	printf("\n");

	printf(BOLD "Exercise 4: ft_is_sort\n" RESET);
	char* ex4_expected[] = {"ft_is_sort.c", NULL};
	check_allowed_files("ex4", ex4_expected, NULL);
	check_norminette("ex4", "");
	check_allowed_functions("ex4", test_path, NULL);
	printf("\n");
	test_func("ex4", test_path);
	printf("\n");
}

void check_c_memory_management(void) {
	char test_path[TMP_SIZE];
	snprintf(test_path, sizeof(test_path), "%s/res/C Memory Management", get_self_path());

	printf(BOLD "Exercise 0: ft_strdup\n" RESET);
	char* ex0_expected[] = {"ft_strdup.c", NULL};
	char* ex0_allowed[] = {"malloc", NULL};
	check_allowed_files("ex0", ex0_expected, NULL);
	check_norminette("ex0", "");
	check_allowed_functions("ex0", test_path, ex0_allowed);
	printf("\n");
	test_func("ex0", test_path);
	printf("\n");

	printf(BOLD "Exercise 1: ft_range\n" RESET);
	char* ex1_expected[] = {"ft_range.c", NULL};
	char* ex1_allowed[] = {"malloc", NULL};
	check_allowed_files("ex1", ex1_expected, NULL);
	check_norminette("ex1", "");
	check_allowed_functions("ex1", test_path, ex1_allowed);
	printf("\n");
	test_func("ex1", test_path);
	printf("\n");

	printf(BOLD "Exercise 2: ft_ultimate_range\n" RESET);
	char* ex2_expected[] = {"ft_ultimate_range.c", NULL};
	char* ex2_allowed[] = {"malloc", NULL};
	check_allowed_files("ex2", ex2_expected, NULL);
	check_norminette("ex2", "");
	check_allowed_functions("ex2", test_path, ex2_allowed);
	printf("\n");
	test_func("ex2", test_path);
	printf("\n");

	printf(BOLD "Exercise 3: ft_strjoin\n" RESET);
	char* ex3_expected[] = {"ft_strjoin.c", NULL};
	char* ex3_allowed[] = {"malloc", NULL};
	check_allowed_files("ex3", ex3_expected, NULL);
	check_norminette("ex3", "");
	check_allowed_functions("ex3", test_path, ex3_allowed);
	printf("\n");
	test_func("ex3", test_path);
	printf("\n");

	printf(BOLD "Exercise 4: ft_convert_base\n" RESET);
	char* ex4_expected[] = {"ft_convert_base.c", "ft_convert_base2.c", NULL};
	char* ex4_allowed[] = {"malloc", "free", NULL};
	check_allowed_files("ex4", ex4_expected, NULL);
	check_norminette("ex4", "");
	check_allowed_functions("ex4", test_path, ex4_allowed);
	printf("\n");
	test_func("ex4", test_path);
	printf("\n");

	printf(BOLD "Exercise 5: ft_split\n" RESET);
	char* ex5_expected[] = {"ft_split.c", NULL};
	char* ex5_allowed[] = {"malloc", NULL};
	check_allowed_files("ex5", ex5_expected, NULL);
	check_norminette("ex5", "");
	check_allowed_functions("ex5", test_path, ex5_allowed);
	printf("\n");
	test_func("ex5", test_path);
	printf("\n");
}

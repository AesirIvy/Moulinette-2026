#include "mostima.h"

void check_c_strings(void) {
	char test_path[BUF_SIZE];
	snprintf(test_path, sizeof(test_path), "%s/res/test/C Strings", get_self_path());

	printf(BOLD "Exercise 0: ft_strcpy\n" RESET);
	char* ex0_expected[] = {"ft_strcpy.c", NULL};
	check_allowed_files("ex0", ex0_expected, NULL);
	check_norminette("ex0", "");
	check_allowed_functions("ex0", test_path, "");
	printf("\n");
	test_func("ex0", test_path);
	printf("\n");

	printf(BOLD "Exercise 1: ft_strncpy\n" RESET);
	char* ex1_expected[] = {"ft_strncpy.c", NULL};
	check_allowed_files("ex1", ex1_expected, NULL);
	check_norminette("ex1", "");
	check_allowed_functions("ex1", test_path,  "");
	printf("\n");
	test_func("ex1", test_path);
	printf("\n");

	printf(BOLD "Exercise 2: ft_strcmp\n" RESET);
	char* ex2_expected[] = {"ft_strcmp.c", NULL};
	check_allowed_files("ex2", ex2_expected, NULL);
	check_norminette("ex2", "");
	check_allowed_functions("ex2", test_path,  "");
	printf("\n");
	test_func("ex2", test_path);
	printf("\n");

	printf(BOLD "Exercise 3: ft_strncmp\n" RESET);
	char* ex3_expected[] = {"ft_strncmp.c", NULL};
	check_allowed_files("ex3", ex3_expected, NULL);
	check_norminette("ex3", "");
	check_allowed_functions("ex3", test_path,  "");
	printf("\n");
	test_func("ex3", test_path);
	printf("\n");

	printf(BOLD "Exercise 4: ft_strcat\n" RESET);
	char* ex4_expected[] = {"ft_strcat.c", NULL};
	check_allowed_files("ex4", ex4_expected, NULL);
	check_norminette("ex4", "");
	check_allowed_functions("ex4", test_path,  "");
	printf("\n");
	test_func("ex4", test_path);
	printf("\n");

	printf(BOLD "Exercise 5: ft_strncat\n" RESET);
	char* ex5_expected[] = {"ft_strncat.c", NULL};
	check_allowed_files("ex5", ex5_expected, NULL);
	check_norminette("ex5", "");
	check_allowed_functions("ex5", test_path,  "");
	printf("\n");
	test_func("ex5", test_path);
	printf("\n");

	printf(BOLD "Exercise 6: ft_strstr\n" RESET);
	char* ex6_expected[] = {"ft_strstr.c", NULL};
	check_allowed_files("ex6", ex6_expected, NULL);
	check_norminette("ex6", "");
	check_allowed_functions("ex6", test_path,  "");
	printf("\n");
	test_func("ex6", test_path);
	printf("\n");

	printf(BOLD "Exercise 7: ft_atoi\n" RESET);
	char* ex7_expected[] = {"ft_atoi.c", NULL};
	check_allowed_files("ex7", ex7_expected, NULL);
	check_norminette("ex7", "");
	check_allowed_functions("ex7", test_path,  "");
	printf("\n");
	test_func("ex7", test_path);
	printf("\n");
}

void check_c_structures(void) {
	char test_path[BUF_SIZE];
	snprintf(test_path, sizeof(test_path), "%s/res/test/C Structures", get_self_path());

	printf(BOLD "Exercise 0: ft_point.h\n" RESET);
	char* ex0_expected[] = {"ft_point.h", NULL};
	check_allowed_files("ex0", ex0_expected, NULL);
	check_norminette("ex0", "");
	check_allowed_functions("ex0", test_path,  "");
	printf("\n");
	test_func("ex0", test_path);
	printf("\n");

	printf(BOLD "Exercise 1: ft_strs_to_tab\n" RESET);
	char* ex1_expected[] = {"ft_strs_to_tab.c", NULL};
	check_allowed_files("ex1", ex1_expected, NULL);
	check_norminette("ex1", "");
	check_allowed_functions("ex1", test_path, "malloc free");
	printf("\n");
	test_func("ex1", test_path);
	printf("\n");

	printf(BOLD "Exercise 2: ft_show_tab\n" RESET);
	char* ex2_expected[] = {"ft_show_tab.c", NULL};
	check_allowed_files("ex2", ex2_expected, NULL);
	check_norminette("ex2", "");
	check_allowed_functions("ex2", test_path, "write");
	printf("\n");
	test_func("ex2", test_path);
	printf("\n");
}

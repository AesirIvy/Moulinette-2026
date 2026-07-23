#ifndef MOSTIMA_H
#define MOSTIMA_H

#include <stdio.h>
#include <stdlib.h>

#define TMP_SIZE 512
#define BUF_SIZE 1024
#define OUT_SIZE 16384

#define TAB   "    "
#define FTAB  "      "
#define NTAB  "         "
#define FNTAB "  "

#define RED     "\033[0;31m"
#define GREEN   "\033[0;32m"
#define YELLOW  "\033[0;33m"
#define BLUE    "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN    "\033[0;36m"
#define BOLD    "\033[1m"
#define RESET   "\033[0m"

// defined in check.c
void check(void);
void check_norminette(char* path, char* flag);
void check_allowed_files(const char* dir, char** expected, char** allowed_ext);
void check_allowed_functions(const char* dir, const char* test_path, char* allowed_func);

// defined in utile.c
char* get_self_path(void);
void test_func(const char* dir, const char* test_path);
void test_prog(const char *dir, const char *args, const char *expected_stdout, const char *expected_stderr);

// defined in module/check_mm.c
void check_c_pointers(void);
void check_c_simple_strings(void);
void check_c_function_pointers(void);
void check_c_memory_management(void);
void check_c_system_interface(void);

// defined in module/check_ds.c
void check_c_strings(void);
void check_c_structures(void);

#endif

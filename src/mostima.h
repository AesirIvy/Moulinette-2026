#ifndef MOSTIMA_H
#define MOSTIMA_H

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
void check();
void check_norminette(char* path);
void check_allowed_files(const char* dir, char** expected, char** allowed_ext);
void check_allowed_functions(const char* dir, char** allowed_func);

// defined in print.c
void print_help(void);
void print_report(char* project);

// defined in utile.c
char* get_self_path(void);
void test_func(char* dir, char* test);

// defined in module/check_mm.c
void check_c_pointers();

#endif

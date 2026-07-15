#ifndef MOSTIMA_H
#define MOSTIME_H

#define BUF_SIZE 1024

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

// defined in print.c
void print_help(void);
void print_report(char* project);

// defined in utile.c
char* get_cwd(void);

#endif

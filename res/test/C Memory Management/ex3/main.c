#include "exusiai.h"

char* ft_strjoin(int size, char** strs, char* sep);

static void fill_str(int size, char **strs, char *sep, char *res) {
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			res[k] = strs[i][j];
			++j;
			++k;
		}
		j = 0;
		while (sep[j] != '\0' && i != size - 1)
		{
			res[k] = sep[j];
			++j;
			++k;
		}
		++i;
	}
}

static char* strjoin(int size, char **strs, char *sep)
{
	int i;

	i = 0;
	int res_len = 0;
	if (size == 0)
	{
		char* res = (char *)malloc(1);
		res[0] = '\0';
		return (res);
	}
	int sep_len = strlen(sep);
	while (i < size)
	{
		res_len += strlen(strs[i]) + sep_len;
		++i;
	}
	res_len -= sep_len;
	char* res = (char*)malloc(sizeof(char) * (res_len + 1));
	i = 0;
	fill_str(size, strs, sep, res);
	res[res_len] = '\0';
	return (res);
}


char* random_printable_str(int len) {
	char* buf = malloc(sizeof(char) * len);
	for (int i = 0; i < len; ++i) {
		buf[i] = rand() % 95 + 32;
	}
	buf[len] = '\0';
	return buf;
}

char** random_printable_strs(int lst_len, int str_len) {
	char** buf = (char**)malloc(sizeof(char*) * lst_len);
	for (int i = 0; i < lst_len; ++i) {
		buf[i] = (char*)malloc(sizeof(char) * str_len);
		for (int j = 0; j < str_len; ++j) {
			buf[i][j] = rand() % 95 + 32;
		}
		buf[str_len] = '\0';
	}
	return buf;
}

int main() {
	int size;
	char* out;
	char* res;
	char* sep;
	char** strs;

	strs = random_printable_strs(0, 0);
	out = ft_strjoin(0, strs, "");
	if (strcmp(out, "") != 0) {
		printf(TAB RED "Didn't return an empty string when size is 0" RESET "\n\n");
		exit(EXIT_FAILURE);
	}
	free(out);
	printf(TAB GREEN "Handles size is 0\n" RESET);

	srand(time(NULL));
	strs = random_printable_strs(1, rand() % 10 + 5);
	sep = random_printable_str(rand() % 10 + 1);
	res = strjoin(1, strs, sep);
	out = ft_strjoin(1, strs, sep);
	if (strcmp(out, res) != 0) {
		printf(TAB RED "Doesn't handle single string" RESET "\n\n");
		exit(EXIT_FAILURE);
	}
	printf(TAB GREEN "Handles single strins\n" RESET);

	strs = random_printable_strs(1, rand() % 10 + 5);
	sep = random_printable_str(rand() % 10 + 1);
	res = strjoin(1, strs, sep);
	out = ft_strjoin(1, strs, sep);
	if (strcmp(out, res) != 0) {
		printf(TAB RED "Doesn't handle empty separator" RESET "\n\n");
		exit(EXIT_FAILURE);
	}
	printf(TAB GREEN "Handles empty separator\n" RESET);

	size = rand() % 5 + 2;
	strs = random_printable_strs(size, rand() % 10 + 5);
	sep = random_printable_str(rand() % 10 + 1);
	res = strjoin(size, strs, sep);
	out = ft_strjoin(size, strs, sep);
	if (strcmp(out, res) != 0) {
		printf(TAB RED "Doesn't handle random strings" RESET "\n\n");
		exit(EXIT_FAILURE);
	}
	printf(TAB GREEN "Handles random strings\n" RESET);

	strs = random_printable_strs(size, rand() % 10 + 5);
	sep = random_printable_str(rand() % 10 + 1);
	res = strjoin(size - 1 , strs, sep);
	out = ft_strjoin(size - 1, strs, sep);
	if (strcmp(out, res) != 0) {
		printf(TAB RED "Doesn't handle size < len(str)" RESET "\n\n");
		exit(EXIT_FAILURE);
	}
	printf(TAB GREEN "Handles size < len(str)\n" RESET);
	return 0;
}

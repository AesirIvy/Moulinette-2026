#include "exusiai.h"

char** ft_split(char* str, char* charset);

char* random_printable_str(int len) {
	char* buf = malloc(sizeof(char) * len);
	for (int i = 0; i < len; ++i) {
		buf[i] = rand() % 95 + 32;
	}
	buf[len] = '\0';
	return buf;
}

static int is_sep(char c, char *charset) {
	while (*charset) {
		if (*charset == c)
			return (1);
		charset++;
	}
	return (0);
}

static int count_words(char *str, char *charset) {
	int count = 0;
	int in_word = 0;
	while (*str) {
		if (is_sep(*str, charset))
			in_word = 0;
		else {
			if (!in_word) {
				count++;
				in_word = 1;
			}
		}
		str++;
	}
	return (count);
}

static char *dup_word(char *start, int len) {
	char* word = (char *)malloc(sizeof(char) * (len + 1));
	int i = 0;
	while (i < len) {
		word[i] = start[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int fill_result(char** res, char* str, char* charset) {
	int i = 0;
	while (*str) {
		if (is_sep(*str, charset))
			str++;
		else {
			int len = 0;
			while (str[len] && !is_sep(str[len], charset))
				len++;
			res[i] = dup_word(str, len);
			if (!res[i])
				return (0);
			i++;
			str += len;
		}
	}
	res[i] = NULL;
	return (1);
}

static char** split(char *str, char *charset) {
	int words = count_words(str, charset);
	char** result = (char **)malloc(sizeof(char *) * (words + 1));
	if (!fill_result(result, str, charset))
		return (NULL);
	return (result);
}

int main() {
	char** out;

	out = ft_split("", ",");
	if (out[0]) {
		printf(TAB RED "Doesn't handle empty string" RESET "\n\n");
		exit(EXIT_FAILURE);
	}
	printf(TAB GREEN "Handles empty string\n" RESET);

	out = ft_split("placeholder", "");
	if (strcmp(out[0], "placeholder") != 0 || out[1]) {
		printf(TAB RED "Doesn't handle empty charset" RESET "\n\n");
		exit(EXIT_FAILURE);
	}
	printf(TAB GREEN "Handles empty charset\n" RESET);

	out = ft_split("text where no sep is present", "auy");
	if (strcmp(out[0], "text where no sep is present") != 0 || out[1]) {
		printf(TAB RED "Doesn't handle string where no separators are present" RESET "\n\n");
		exit(EXIT_FAILURE);
	}
	printf(TAB GREEN "Handles empty charset\n" RESET);

	srand(time(NULL));
	char* str = random_printable_str(70);
	char sep[2] = {str[rand() % 20 + 5], str[rand() % 40 + 25]};
	out = ft_split(str, sep);
	char** res = split(str, sep);
	while (*out && *res) {
		if (strcmp(*out++, *res++) != 0) {
			printf(TAB RED "Doesn't handle random string and separators" RESET "\n\n");
			exit(EXIT_FAILURE);
		}
	}
	if (*res) {
		printf(TAB RED "Doesn't handle random string and separators" RESET "\n\n");
		exit(EXIT_FAILURE);
	}
	printf(TAB GREEN "Handles random string and separators\n" RESET);
	return 0;
}

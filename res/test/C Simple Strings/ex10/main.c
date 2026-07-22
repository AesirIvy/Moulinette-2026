#include "exusiai.h"

void ft_putstr_non_printable(char* str);

char dup_get_hex(int nb) {
	if (nb >= 10)
		return ('a' + nb - 10);
	else
		return ('0' + nb);
}

int parse_escape_char(char* res, int j, int nb) {
	char n1 = dup_get_hex(nb / 16);
	char n2 = dup_get_hex(nb % 16);
	res[j++] = '\\';
	res[j++] = n1;
	res[j++] = n2;
	return j;
}

char* get_non_printable(char *str) {
	int i = 0;
	int j = 0;
	char* res = (char*)malloc(sizeof(char) * (strlen(str) + 1));
	while (str[i])
	{
		if (!(str[i] >= 32 && str[i] <= 126))
			j = parse_escape_char(res, j, str[i]);
		else
			res[j++] = str[i];
		++i;
	}
	res[j] = '\0';
	return res;
}

char* random_non_printable_string(size_t len) {
	char* str = malloc(len + 1);
	if (str == NULL) {
		return NULL;
	}
	srand(time(NULL));
	for (size_t i = 0; i < len; ++i) {
		str[i] = (char)(rand() % 31 + 1);
	}
	str[len] = '\0';
	return str;
}

char* random_printable_string(size_t len) {
	char* str = malloc(len + 1);
	if (str == NULL) {
		return NULL;
	}
	srand(time(NULL));
	for (size_t i = 0; i < len; ++i) {
		str[i] = (char)(rand() % (127 - 32) + 32);
	}
	str[len] = '\0';
	return str;
}

static void capture_output(char *str, char *out_buf, size_t buf_size) {
	const char* tmp_file = "temp.txt";
	FILE* fp;
	if (freopen(tmp_file, "w", stdout) == NULL) {
		fprintf(stderr, "can't open the file\n");
		exit(EXIT_FAILURE);
	}
	ft_putstr_non_printable(str);
	fflush(stdout);
	if (freopen("/dev/tty", "w", stdout) == NULL) {
		fprintf(stderr, "stdout restore failed\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(tmp_file, "r");
	if (!fp) {
		fprintf(stderr, "can't open %s\n", tmp_file);
		remove(tmp_file);
		exit(EXIT_FAILURE);
	}
	fgets(out_buf, buf_size, fp);
	fclose(fp);
	remove(tmp_file);
}

int main() {
	char out[BUF_SIZE];
	capture_output("", out, sizeof(out));
	if (*out) {
		printf(TAB RED "Output presents when input is empty\n\n" RESET);
		exit(EXIT_FAILURE);
	}
	printf(TAB GREEN "Handles empty string\n" RESET);

	char* str = random_printable_string(random() % 32 + 32);
	char* res = get_non_printable(str);	
	capture_output(str, out, sizeof(out));
	if (strcmp(out, res) != 0) {
		printf(TAB RED "Incorrect string printed\n\n" RESET);
		printf("Expected: %s\n", res);
		printf("Get: %s\n\n", out);
		exit(EXIT_FAILURE);
	}
	printf(TAB GREEN "Handles alpha string\n" RESET);

	strcat(str, random_non_printable_string(random() % 32 + 16));
	res = get_non_printable(str);
	capture_output(str, out, sizeof(out));
	if (strcmp(out, res) != 0) {
		printf(TAB RED "Incorrect string printed\n\n" RESET);
		printf("Expected: %s\n", res);
		printf("Get: %s\n\n", out);
		exit(EXIT_FAILURE);
	}
	printf(TAB GREEN "Handles random string\n" RESET);
	return 0;
}

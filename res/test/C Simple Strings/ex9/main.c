#include "exusiai.h"

void ft_putstr(char* str);

char* random_string(size_t len) {
	char* str = malloc(len + 1);
	if (str == NULL) {
		return NULL;
	}
	srand(time(NULL));
	for (size_t i = 0; i < len; ++i) {
		str[i] = (char)(rand() % (126 - 14) + 14);
	}
	str[len] = '\0';
	return str;
}

int main() {
	char* str = random_string(64);
	const char* tmp_file = "tmp.txt";
	freopen(tmp_file, "w", stdout);
	ft_putstr("");
	fflush(stdout);
	freopen("/dev/tty", "w", stdout);
	FILE *fp = fopen(tmp_file, "r");
	if (!fp) {
		fprintf(stderr, "can't open the file");
		remove(tmp_file);
		exit(EXIT_FAILURE);
	}
	char line[BUF_SIZE];
	if (fgets(line, sizeof(line), fp)) {
		printf(TAB RED "Output presents when input is empty\n\n" RESET);
		exit(EXIT_FAILURE);
	}
	printf(TAB GREEN "Handles empty str\n" RESET);

	rewind(fp);
	freopen(tmp_file, "w", stdout);
	ft_putstr(str);
	fflush(stdout);
	freopen("/dev/tty", "w", stdout);
	if (!fgets(line, sizeof(line), fp)) {
		printf(TAB RED "No output for non empty str\n\n" RESET);
		exit(EXIT_FAILURE);
	}
	if (strcmp(line, str) != 0) {
		printf(TAB RED "Incorrect str printed\n\n" RESET);
		printf("Expecting: %s\n", str);
		printf("Get: %s\n\n", line);
		exit(EXIT_FAILURE);
	}
	fclose(fp);
	remove(tmp_file);
	free(str);
	return 0;
}

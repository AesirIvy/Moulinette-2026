#include "exusiai.h"

void ft_foreach(int* tab, int length, void (*f)(int));

void secret_fn(int val) {
	printf("%d\n", val * 2);
}

static int* capture_output(int* tab, int size) {
	char out_buf[BUF_SIZE];
	const char* tmp_file = "temp.txt";
	int* out = (int*)malloc(sizeof(int) * size);
	FILE* fp;
	if (freopen(tmp_file, "w", stdout) == NULL) {
		fprintf(stderr, "can't open the file\n");
		exit(EXIT_FAILURE);
	}
	ft_foreach(tab, size, &secret_fn);
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
	for (int i = 0; i < size; ++i) {
		if (fgets(out_buf, sizeof(out_buf), fp) == NULL) {
			printf(TAB RED "Your function isn't applied to every items" RESET "\n\n");
			exit(EXIT_FAILURE);
		}
		out[i] = atoi(out_buf);
	}
	fclose(fp);
	remove(tmp_file);
	return out;
}

int main() {
	srand(time(NULL));
	int size = random() % 10 + 10;
	int tab[size];
	for (int i = 0; i < size; ++i)
		tab[i] = RAND_INT;
	int* out = capture_output(tab, size);
	for (int i = 0; i < size; ++i) {
		if (out[i] != tab[i] * 2) {
			printf(TAB RED "Items in tab are incorrectly displayed" RESET "\n\n");
			printf("For i = %d", i);
			printf("Expecting: %d", tab[i] * 2);
			printf("Get: %d\n\n", out[i]);
			exit(EXIT_FAILURE);
		}
	}
	printf(TAB GREEN "Handles mysterious function\n" RESET);
	free(out);
	return 0;
}

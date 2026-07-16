#include "exusiai.h"

int ft_atoi(char *str);

int random_sign(char* str, int len) {
	if (len <= 0) return 1;

	char chars[] = {'+', '-', ' ', '\t', '\n', '\v', '\f', '\r'};
	int sign = 1;
	int i = 0;
	while(i < len) {
		str[i] = chars[rand() % (sizeof(chars) - 1)];
		if (str[i] == '-')
			sign *= -1;
		++i;
	}
	str[i] = '\0';
	return sign;
}

int main() {
	int out = ft_atoi("");
	if (out == 0)
		printf(TAB GREEN "Handles empty string\n" RESET);
	else {
		printf(TAB RED "Doesn't handle empty string\n\n" RESET);
		printf("Expecting: 0\n");
		printf("Get: %d\n\n", out);
		return 1;
	}

	char* str = (char*)malloc(sizeof(char) * 32);
	int n = RAND_INT;
	sprintf(str, "%d", n);
	out = ft_atoi(str);
	if (out == n)
		printf(TAB GREEN "Handles random integer\n" RESET);
	else {
		printf(TAB RED "Doesn't handle random integer\n\n" RESET);
		printf("Expecting: %d\n", n);
		printf("Get: %d\n\n", out);
		return 1;
	}

	char* tmp = (char*)malloc(sizeof(char) * 32);
	srand(time(NULL));
	int sign = random_sign(str, random() % 15 + 5);
	n = random() % INT_MAX;
	sprintf(tmp, "%d", n);
	strcat(str, tmp);
	out = ft_atoi(str);
	if (out == sign * n)
		printf(TAB GREEN "Handles minimum integer\n" RESET);
	else {
		printf(TAB RED "Doesn't handle minimum integer\n\n" RESET);
		printf("Expecting: %d\n", sign * n);
		printf("Get: %d\n\n", out);
		return 1;
	}

	out = ft_atoi("0");
	if (out == 0)
		printf(TAB GREEN "Handles zero as input\n" RESET);
	else {
		printf(TAB RED "Doesn't handle zero as input\n\n" RESET);
		printf("Expecting: 0\n");
		printf("Get: %d\n\n", out);
		return 1;
	}

	sprintf(str, "%d", INT_MIN);
	out = ft_atoi(str);
	if (out == INT_MIN)
		printf(TAB GREEN "Handles minimum integer\n" RESET);
	else {
		printf(TAB RED "Doesn't handle minimum integer\n\n" RESET);
		printf("Expecting: %d\n", INT_MIN);
		printf("Get: %d\n\n", out);
		return 1;
	}

	sprintf(str, "%d", INT_MAX);
	out = ft_atoi(str);
	if (out == INT_MAX)
		printf(TAB GREEN "Handles maximum integer\n" RESET);
	else {
		printf(TAB RED "Doesn't handle maximum integer\n\n" RESET);
		printf("Expecting: %d\n", INT_MAX);
		printf("Get: %d\n\n", out);
		return 1;
	}
	free(tmp);
	free(str);
	return 0;
}

#include "exusiai.h"

char* ft_convert_base(char* nbr, char* base_from, char* base_to);

static int is_valid_base(char *base) {
	if (!base || strlen(base) < 2)
		return (0);
	int i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| (base[i] >= 9 && base[i] <= 13))
			return (0);
		int j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

static int get_index(char c, char *base) {
	int i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static long atoi_base(char *nbr, char *base, int base_len) {
	long result = 0;
	int sign = 1;
	while (*nbr == ' ' || (*nbr >= 9 && *nbr <= 13))
		nbr++;
	while (*nbr == '+' || *nbr == '-') {
		if (*nbr == '-')
			sign *= -1;
		nbr++;
	}
	while (*nbr) {
		int idx = get_index(*nbr, base);
		if (idx == -1)
			break ;
		result = result * base_len + idx;
		nbr++;
	}
	return (result * sign);
}

static int num_len(long nbr, int base_len, int neg) {
	int len = neg ? 1 : 0;
	if (nbr == 0)
		len = 1;
	while (nbr > 0) {
		nbr /= base_len;
		len++;
	}
	return (len);
}

static char* itoa_base(long nbr, char* base, int base_len) {
	int neg = 0;
	if (nbr < 0) {
		neg = 1;
		nbr = -nbr;
	}
	int len = num_len(nbr, base_len, neg);
	char* res = (char *)malloc(sizeof(char) * (len + 1));
	res[len--] = '\0';
	while (len >= 0) {
		res[len--] = base[nbr % base_len];
		nbr /= base_len;
	}
	if (neg)
		res[0] = '-';
	return (res);
}

static char* convert_base(char* nbr, char* base_from, char* base_to) {
	int len_from = is_valid_base(base_from);
	int len_to = is_valid_base(base_to);
	if (!len_from || !len_to)
		return (NULL);
	long num = atoi_base(nbr, base_from, len_from);
	return (itoa_base(num, base_to, len_to));
}

int main() {
	char bin[] = "01";
	char dec[] = "0123456789";
	char hex[] = "0123456789ABCDEF";

	char n[BUF_SIZE];
	char* out;
	char* res;

	char* out_n0 = ft_convert_base(n, dec, "");
	char* out_n1 = ft_convert_base(n, "yoyo", dec);
	char* out_n2 = ft_convert_base(n, dec, "\n\v\f\r");
	char* out_n3 = ft_convert_base(n, "+-", dec);
	if (out_n0 || out_n1 || out_n2 || out_n3) {
		printf(TAB RED "Doesn't handle invalid base" RESET "\n\n");
		exit(EXIT_FAILURE);
	}
	printf(TAB GREEN "Handles invilid base\n" RESET);

	srand(time(NULL));
	snprintf(n, sizeof(n), "%d", RAND_INT);
	out = ft_convert_base(n, dec, bin);
	res = convert_base(n, dec, bin);
	if (strcmp(out, res) != 0) {
		printf(TAB RED "Doesn't handle decimal to binary" RESET "\n\n");
		printf("Expecting: %s\n", res);
		printf("Get: %s\n\n", out);
		exit(EXIT_FAILURE);
	}
	printf(TAB GREEN "Handles decimal to binary\n" RESET);

	out = ft_convert_base(res, bin, dec);
	if (strcmp(out, n) != 0) {
		printf(TAB RED "Doesn't handle binary to decimal" RESET "\n\n");
		printf("Expecting: %s\n", n);
		printf("Get: %s\n\n", out);
		exit(EXIT_FAILURE);
	}
	printf(TAB GREEN "Handles binary to decimal\n" RESET);

	snprintf(n, sizeof(n), "%d", RAND_INT);
	out = ft_convert_base(n, dec, hex);
	res = convert_base(n, dec, hex);
	if (strcmp(out, res) != 0) {
		printf(TAB RED "Doesn't handle decimal to hexadecimal" RESET "\n\n");
		printf("Expecting: %s\n", n);
		printf("Get: %s\n\n", out);
		exit(EXIT_FAILURE);
	}
	printf(TAB GREEN "Handles decimal to hexadecimal\n" RESET);

	out = ft_convert_base(res, hex, dec);
	if (strcmp(out, n) != 0) {
		printf(TAB RED "Doesn't handle hexadecimal to decimal" RESET "\n\n");
		printf("Expecting: %s\n", n);
		printf("Get: %s\n\n", out);
		exit(EXIT_FAILURE);
	}
	printf(TAB GREEN "Handles hexadecimal to decimal\n" RESET);

	snprintf(n, sizeof(n), "%d", RAND_INT);
	out = ft_convert_base(n, dec, "arknights");
	res = convert_base(n, dec, "arknights");
	if (strcmp(out, res) != 0) {
		printf(TAB RED "Doesn't handle decimal to random base" RESET "\n\n");
		printf("Expecting: %s\n", res);
		printf("Get: %s\n\n", out);
		exit(EXIT_FAILURE);
	}
	printf(TAB GREEN "Handles decimal to random base\n" RESET);
	return 0;
}

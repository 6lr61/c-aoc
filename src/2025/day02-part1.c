#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

bool invalid_id(const char *str, size_t l)
{
	for (int i = 0; i < l / 2; i++) {
		if (str[i] != str[i + l/2]) {
			return false;
		}
	}

	return true;
}

int main()
{
	const char *del = ",";
	char *str = NULL;
	char *sub_str;
	size_t n;
	getline(&str, &n, stdin);
	sub_str = strtok(str, del);

	unsigned long long int sum = 0;
	
	do {
		long int first, last;
		sscanf(sub_str, "%ld-%ld", &first, &last);

		// 123123, / 1000 - 123, % 1000 - 123
		for (long int n = first; n <= last; n++) {
			int exp = ceill(log10l(n)) / 2;
			int half_tens = powl(10, exp);
			int top = n / half_tens;
			int bottom = n % half_tens;

			if (top == bottom) {
				sum += n;
			}
		}

	} while ((sub_str = strtok(NULL, del)) != NULL);

	printf("%llu\n", sum);

	free(str);

	return 0;
}

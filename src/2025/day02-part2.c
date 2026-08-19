#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// we start with the largest possible chunk,
// that is half the number
// 1001001 breaks everything

bool invalid_id(long int n, long int tens) {
	// for every time we divide the number by the tens
	// 123123 / 1000, then what we are left with, 123
	// should equal 123123 % 1000,
	// 121212 / 100, 1212, 12 % 100 == 121212 % 100
	
	// 1000, 100, 10
	// n > tens
	
	for (long int t = tens; t >= 10; t /= 10) {
		if ((int)ceill(log10l(n)) % (int)log10l(t) != 0) {
			continue;
		}

		long int chunk = n % t;
		bool invalid = true;

		for (long int rem = n; rem > 0; rem /= t) {
			invalid &= (rem % t == chunk);
		}

		if (invalid) {
			return true;
		}
	}

	return false;
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
			long int half_tens = powl(10, exp);

			if (invalid_id(n, half_tens)) {
				sum += n;
			}
		}

	} while ((sub_str = strtok(NULL, del)) != NULL);

	printf("%llu\n", sum);

	free(str);

	return 0;
}

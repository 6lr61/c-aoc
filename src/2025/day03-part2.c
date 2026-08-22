#include <stdio.h>

int main()
{
	size_t N = 0;
	char *str = NULL;
	long long int sum = 0;
	while ((N = getline(&str, &N, stdin)) != EOF) {
		if (str[N-1] == '\n') {
			N = N-1;
		}
		
		// N digits, 0 to n-1
		// find the the largest digit, for 0 to n-2
		// (1 to n-12) - 1
		char max = '0';
		int l = 0;
		long int joltage = 0;
		for (int u = 12; u >= 1; u--) {
			for (int i = l; i <= N-u; i++) {
				if (str[i] > max) {
					max = str[i];
					l = i;
				}
			}

			joltage = joltage * 10 + (max - '0');
			max = '0';
			l++;
		}

		sum += joltage;
	}

	printf("%lld\n", sum);
}

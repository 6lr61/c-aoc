#include <stdio.h>

int main()
{
	// it's two digits
	// 9 and there is a digit following it,
	// then the largest digit following it,
	// is the largest joltage
	size_t N = 0;
	char *str = NULL;
	long int sum = 0;
	while ((N = getline(&str, &N, stdin)) != EOF) {
		if (str[N-1] == '\n') {
			N = N-1;
		}

		// N digits, 0 to n-1
		// find the the largest digit, for 0 to n-2
		char max = '0';
		int k = 0;
		for (int i = 0; i < N-1; i++) {
			// todo: find max
			// record the index
			if (str[i] > max) {
				max = str[i];
				k = i;
			}
		}

		int joltage = 10 * (max - '0');
		max = '0';
		for (int j = k + 1; j < N; j++) {
			// todo: find max in remaining sub sequence
			// and bob's your uncle
			if (str[j] > max) {
				max = str[j];
				k = j;
			}
		}

		joltage += max - '0';
		sum += joltage;
	}

	printf("%ld\n", sum);
}

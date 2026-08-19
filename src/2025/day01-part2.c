#include <stdio.h>
#include <stdlib.h>

int mod(int n) {
	return ((n % 100) + 100) % 100;
}

int main(int argc, const char *argv[])
{
	int dial = 50;
	int zeros = 0;
	char dir;
	int clicks;

	while (scanf("%c%d\n", &dir, &clicks) != EOF) {
		int rotations = clicks / 100;
		int steps = clicks % 100;

		if (dir == 'L') {
			if (dial - steps <= 0 && dial != 0) {
				zeros++;
			}

			dial = mod(dial - clicks);
		} else {
			if (dial + steps >= 100) {
				zeros++;
			}

			dial = mod(dial + clicks);
		}

		zeros += rotations;

		printf("dir: %c, c: %d, d: %d, z: %d\n",
				dir, clicks, dial, zeros);
	}

	printf("%d\n", zeros);

	return 0;
}

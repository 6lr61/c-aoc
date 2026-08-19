#include <stdio.h>

int main(int argc, const char *argv[])
{
	int dial = 50;
	int zeros = 0;
	char dir;
	int clicks;

	while (scanf("%c%d\n", &dir, &clicks) != EOF) {
		if (dir == 'L') {
			dial = (dial - clicks + 100) % 100;
		} else {
			dial = (dial + clicks) % 100;
		}

		if (dial == 0) {
			zeros++;
		}
	}

	printf("%d\n", zeros);

	return 0;
}

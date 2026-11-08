#include <stdbool.h>
#include <stdio.h>

bool
rotateString(char *s, char *goal);

void
example1(void)
{
	printf("main.c:/example1/\n");

	bool rotated = rotateString("abcde", "cdeab"); // true

	printf("rotated: %d\n", rotated);
	printf("\n");
}

void
example2(void)
{
	printf("main.c:/example2/\n");

	bool rotated = rotateString("abcde", "abced"); // false

	printf("rotated: %d\n", rotated);
	printf("\n");
}

int
main(void)
{
	example1();
	example2();

	return 0;
}

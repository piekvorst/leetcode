#include <stdbool.h>
#include <stdio.h>

bool
isCircularSentence(char *sentence);

void
example1(void)
{
	printf("main.c:/example1/\n");

	bool circular = isCircularSentence("leetcode exercises sound delightful"); // true

	printf("circular: %d\n", circular);
	printf("\n");
}

void
example2(void)
{
	printf("main.c:/example2/\n");

	bool circular = isCircularSentence("eetcode"); // true

	printf("circular: %d\n", circular);
	printf("\n");
}

void
example3(void)
{
	printf("main.c:/example3/\n");

	bool circular = isCircularSentence("Leetcode is cool"); // false

	printf("circular: %d\n", circular);
	printf("\n");
}

int
main(void)
{
	example1();
	example2();
	example3();

	return 0;
}

#include <stdio.h>

int
minChanges
	(char *s);

void
example1
	(void)
{
	printf("main.c:/example1/\n");

	int changes = minChanges((char []){"1001"}); // 2

	printf("changes: %d\n", changes);
	printf("\n");
}

void
example2
	(void)
{
	printf("main.c:/example2/\n");

	int changes = minChanges((char []){"10"}); // 1

	printf("changes: %d\n", changes);
	printf("\n");
}

void
example3
	(void)
{
	printf("main.c:/example3/\n");

	int changes = minChanges((char []){"0000"}); // 0

	printf("changes: %d\n", changes);
	printf("\n");
}

void
wronganswer1
	(void)
{
	printf("main.c:/wronganswer1/\n");

	int changes = minChanges((char []){"11000111"}); // 1

	printf("changes: %d\n", changes);
	printf("\n");
}

int
main
	(void)
{
	example1();
	example2();
	example3();
	wronganswer1();

	return 0;
}

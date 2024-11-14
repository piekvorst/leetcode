#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof((x)[0]))

int
minimizedMaximum(int n, int *quantities, int qlen);

void
example1(void)
{
	printf("main.c:/example1/\n");

	int quantities[] = {11, 6};
	int x = minimizedMaximum(6, quantities, nelem(quantities)); // 3

	printf("x: %d\n", x);
	printf("\n");
}

void
example2(void)
{
	printf("main.c:/example2/\n");

	int quantities[] = {15, 10, 10};
	int x = minimizedMaximum(7, quantities, nelem(quantities)); // 5

	printf("x: %d\n", x);
	printf("\n");
}

void
example3(void)
{
	printf("main.c:/example3/\n");

	int quantities[] = {100000};
	int x = minimizedMaximum(1, quantities, nelem(quantities)); // 100000

	printf("x: %d\n", x);
	printf("\n");
}

void
wronganswer1(void)
{
	printf("main.c:/wronganswer1/\n");

	int quantities[] = {5, 7};
	int x = minimizedMaximum(2, quantities, nelem(quantities)); // 7

	printf("x: %d\n", x);
	printf("\n");
}

int
main(void)
{
	example1();
	example2();
	example3();
	wronganswer1();

	return 0;
}

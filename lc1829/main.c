#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof((x)[0]))

int *
getMaximumXor
	(int *p, int plen, int exponent, int *qlen);

void
arrprint
	(int *p, int len)
{
	for (int *q = p; q != p+len; ++q)
		printf("	%d", *q);

	printf("\n");
}

void
example1
	(void)
{
	printf("main.c:/example1/\n");

	int p[] = {0, 1, 1, 3};
	int len = 0;
	int *q = getMaximumXor(p, nelem(p), 2, &len); // 0, 3, 2, 3

	arrprint(q, len);
}

void
example2
	(void)
{
	printf("main.c:/example2/\n");

	int p[] = {2, 3, 4, 7};
	int len = 0;
	int *q = getMaximumXor(p, nelem(p), 3, &len); // 5, 2, 6, 5

	arrprint(q, len);
}

void
example3
	(void)
{
	printf("main.c:/example3/\n");

	int p[] = {0, 1, 2, 2, 5, 7};
	int len = 0;
	int *q = getMaximumXor(p, nelem(p), 3, &len); // 4, 3, 6, 4, 6, 7

	arrprint(q, len);
}

int
main
	(void)
{
	example1();
	example2();
	example3();

	return 0;
}

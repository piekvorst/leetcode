#include <stdbool.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof((x)[0]))

bool
primeSubOperation(int *p, int len);

void
example1
	(void)
{
	printf("main.c:/example1/\n");

	int arr[] = {4, 9, 6, 10};
	bool ok = primeSubOperation(arr, nelem(arr)); // 1

	printf("ok: %d\n", ok);
	printf("\n");
}

void
example2
	(void)
{
	printf("main.c:/example2/\n");

	int arr[] = {6, 8, 11, 12};
	bool ok = primeSubOperation(arr, nelem(arr)); // 1

	printf("ok: %d\n", ok);
	printf("\n");
}

void
example3
	(void)
{
	printf("main.c:/example3/\n");

	int arr[] = {5, 8, 3};
	bool ok = primeSubOperation(arr, nelem(arr)); // 0

	printf("ok: %d\n", ok);
	printf("\n");
}

void
wronganswer1
	(void)
{
	printf("main.c:/wronganswer1/\n");

	int arr[] = {8, 19, 3, 4, 9};
	bool ok = primeSubOperation(arr, nelem(arr)); // 1

	printf("ok: %d\n", ok);
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

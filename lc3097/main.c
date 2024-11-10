#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof((x)[0]))

int
minimumSubarrayLength
	(int *p, int len, int k);

void
example1
	(void)
{
	printf("main.c:/example1/\n");

	int arr[] = {1, 2, 3};
	int len = minimumSubarrayLength(arr, nelem(arr), 2); // 1

	printf("len: %d\n", len);
	printf("\n");
}

void
example2
	(void)
{
	printf("main.c:/example2/\n");

	int arr[] = {2, 1, 8};
	int len = minimumSubarrayLength(arr, nelem(arr), 10); // 3

	printf("len: %d\n", len);
	printf("\n");
}

void
example3
	(void)
{
	printf("main.c:/example3/\n");

	int arr[] = {1, 2};
	int len = minimumSubarrayLength(arr, nelem(arr), 0); // 1

	printf("len: %d\n", len);
	printf("\n");
}

void
wronganswer1
	(void)
{
	printf("main.c:/wronganswer1/\n");

	int arr[] = {1, 2, 32, 21};
	int len = minimumSubarrayLength(arr, nelem(arr), 55); // 3

	printf("len: %d\n", len);
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

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof((x)[0]))

long long
maximumSubarraySum(int *p, int len, int k);

void
example1(void)
{
	printf("main.c:/example1/\n");

	int arr[] = {1, 5, 4, 2, 9, 9, 9};
	int sum = maximumSubarraySum(arr, nelem(arr), 3); // 15

	printf("sum: %d\n", sum);
	printf("\n");
}

void
example2(void)
{
	printf("main.c:/example2/\n");

	int arr[] = {4, 4, 4};
	int sum = maximumSubarraySum(arr, nelem(arr), 3); // 0

	printf("sum: %d\n", sum);
	printf("\n");
}

void
wronganswer1(void)
{
	printf("main.c:/wronganswer1/\n");

	int arr[] = {1, 1, 1, 7, 8, 9};
	int sum = maximumSubarraySum(arr, nelem(arr), 3); // 24

	printf("sum: %d\n", sum);
	printf("\n");
}

void
wronganswer2(void)
{
	printf("main.c:/wronganswer2/\n");

	int arr[] = {9, 9, 9, 1, 2, 3};
	int sum = maximumSubarraySum(arr, nelem(arr), 3); // 12

	printf("sum: %d\n", sum);
	printf("\n");
}

void
runtimeerror1(void)
{
	printf("main.c:/runtimeerror1/\n");

	int arr[] = {1, 1, 1, 1, 1, 1};
	int sum = maximumSubarraySum(arr, nelem(arr), 1); // 1

	printf("sum: %d\n", sum);
	printf("\n");
}

int
main(void)
{
	example1();
	example2();
	wronganswer1();
	wronganswer2();
	runtimeerror1();

	return 0;
}

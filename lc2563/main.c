#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof((x)[0]))

long long
countFairPairs(int *p, int len, int lower, int upper);

void
example1(void)
{
	printf("main.c:/example1/\n");

	int arr[] = {0, 1, 7, 4, 4, 5};
	long long pairs = countFairPairs(arr, nelem(arr), 3, 6); // 6

	printf("pairs: %lld\n", pairs);
	printf("\n");
}

void
example2(void)
{
	printf("main.c:/example2/\n");

	int arr[] = {1, 7, 9, 2, 5};
	long long pairs = countFairPairs(arr, nelem(arr), 11, 11); // 1

	printf("pairs: %lld\n", pairs);
	printf("\n");
}

void
wronganswer1(void)
{
	printf("main.c:/wronganswer1/\n");

	int arr[] = {0, 0, 0, 0, 0, 0};
	long long pairs = countFairPairs(arr, nelem(arr), 0, 0); // 15

	printf("pairs: %lld\n", pairs);
	printf("\n");
}

int
main(void)
{
	example1();
	example2();
	wronganswer1();

	return 0;
}

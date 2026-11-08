#include <stdio.h>

#define nelem(arr) (sizeof(arr) / sizeof((arr)[0]))

int
minimumMountainRemovals(int *arr, int narr);

void
example1(void)
{
	printf("main.c:/example1/\n");

	int arr[] = {1, 3, 1};
	int removals = minimumMountainRemovals(arr, nelem(arr)); // 0

	printf("removals: %d\n", removals);
	printf("\n");
}

void
example2(void)
{
	printf("main.c:/example2/\n");

	int arr[] = {2, 1, 1, 5, 6, 2, 3, 1};
	int removals = minimumMountainRemovals(arr, nelem(arr)); // 3

	printf("removals: %d\n", removals);
	printf("\n");
}

void
wronganswer1(void)
{
	printf("main.c:/wronganswer1/\n");

	int arr[] = {4, 3, 2, 1, 1, 2, 3, 1};
	int removals = minimumMountainRemovals(arr, nelem(arr)); // 4

	printf("removals: %d\n", removals);
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

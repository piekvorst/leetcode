#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof((x)[0]))

int
largestCombination
	(int *arr, int narr);

void
example1
	(void)
{
	printf("main.c:/example1/\n");

	int arr[] = {16, 17, 71, 62, 12, 24, 14};
	int combination = largestCombination(arr, nelem(arr)); // 4

	printf("combination: %d\n", combination);
	printf("\n");
}

void
example2
	(void)
{
	printf("main.c:/example2/\n");

	int arr[] = {8, 8};
	int combination = largestCombination(arr, nelem(arr)); // 2

	printf("combination: %d\n", combination);
	printf("\n");
}

int
main
	(void)
{
	example1();
	example2();

	return 0;
}

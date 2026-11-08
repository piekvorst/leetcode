#include <stdbool.h>
#include <stdio.h>

#define nelem(arr) (sizeof(arr) / sizeof((arr)[0]))

bool
validMountainArray(int *arr, int narr);

void
example1(void)
{
	printf("main.c:/example1/\n");

	int arr[] = {2, 1};
	bool valid = validMountainArray(arr, nelem(arr)); // false

	printf("valid: %d\n", valid);
	printf("\n");
}

void
example2(void)
{
	printf("main.c:/example2/\n");

	int arr[] = {3, 5, 5};
	bool valid = validMountainArray(arr, nelem(arr)); // false

	printf("valid: %d\n", valid);
	printf("\n");
}

void
example3(void)
{
	printf("main.c:/example3/\n");

	int arr[] = {0, 3, 2, 1};
	bool valid = validMountainArray(arr, nelem(arr)); // true

	printf("valid: %d\n", valid);
	printf("\n");
}

void
wronganswer1(void)
{
	printf("main.c:/wronganswer1/\n");

	int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	bool valid = validMountainArray(arr, nelem(arr)); // false

	printf("valid: %d\n", valid);
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

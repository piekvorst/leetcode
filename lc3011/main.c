#include <stdbool.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof((x)[0]))

bool
canSortArray
	(int *nums, int nnums);

void
example1
	(void)
{
	printf("main.c:/example1/\n");

	int nums[] = {8, 4, 2, 30, 15};
	bool sortable = canSortArray(nums, nelem(nums)); // 1

	printf("sortable: %d\n", sortable);
	printf("\n");
}

void
example2
	(void)
{
	printf("main.c:/example2/\n");

	int nums[] = {1, 2, 3, 4, 5};
	bool sortable = canSortArray(nums, nelem(nums)); // 1

	printf("sortable: %d\n", sortable);
	printf("\n");
}

void
example3
	(void)
{
	printf("main.c:/example3/\n");

	int nums[] = {3, 16, 8, 4, 2};
	bool sortable = canSortArray(nums, nelem(nums)); // 0

	printf("sortable: %d\n", sortable);
	printf("\n");
}

// [1 2 3 4 5] is sorted, but [5 4 3 2 1] is not
//
void
custom1
	(void)
{
	printf("main.c:/custom1/\n");

	int nums[] = {5, 4, 3, 2, 1};
	bool sortable = canSortArray(nums, nelem(nums)); // 0

	printf("sortable: %d\n", sortable);
	printf("\n");
}

void
custom2
	(void)
{
	printf("main.c:/custom2/\n");

	int nums[] = {1, 1, 1, 1, 1};
	bool sortable = canSortArray(nums, nelem(nums)); // 1

	printf("sortable: %d\n", sortable);
	printf("\n");
}

int
main
	(void)
{
	example1();
	example2();
	example3();
	custom1();
	custom2();

	return 0;
}

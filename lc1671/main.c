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

void
tle1(void)
{
	printf("main.c:/tle1/\n");

	int arr[] = {
		1, 2, 3, 4, 5, 1000, 999, 998, 997, 996, 995, 994, 993, 992, 991,
		990, 989, 988, 987, 986, 985, 984, 983, 982, 981, 980, 979, 978,
		977, 976, 975, 974, 973, 972, 971, 970, 969, 968, 967, 966, 965,
		964, 963, 962, 961, 960, 959, 958, 957, 956, 955, 954, 953, 952,
		951, 950, 949, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
		20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35,
		36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51,
		52, 53, 54, 55, 56, 57, 58, 59, 60, 1,
	};
	int removals = minimumMountainRemovals(arr, nelem(arr));

	printf("removals: %d\n", removals);
	printf("\n");
}

int
main(void)
{
	example1();
	example2();
	wronganswer1();
	//tle1();

	return 0;
}

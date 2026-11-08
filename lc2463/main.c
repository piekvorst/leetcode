#include <stdio.h>

#define ARRAY_LEN(arr) (sizeof(arr) / sizeof((arr)[0]))

long long
minimumTotalDistance(int *robots, int nrobots, int **factories, int nfactories, int *mfactories);

void
example1(void)
{
	printf("main.c:/^example1/\n");

	int robots[] = {0, 4, 6};
	int *factories[] = {
		(int []){2, 2},
		(int []){6, 2},
	};
	long long dist = minimumTotalDistance(
		robots, ARRAY_LEN(robots),
		factories, ARRAY_LEN(factories), NULL
	); // 4

	printf("dist: %lld\n", dist);
	printf("\n");
}

void
example2(void)
{
	printf("main.c:/^example2/\n");

	int robots[] = {1, -1};
	int *factories[] = {
		(int []){-2, 1},
		(int []){2, 1},
	};
	long long dist = minimumTotalDistance(
		robots, ARRAY_LEN(robots),
		factories, ARRAY_LEN(factories), NULL
	); // 2

	printf("dist: %lld\n", dist);
	printf("\n");
}

void
custom1(void)
{
	printf("main.c:/^custom1/\n");

	int robots[] = {0, 2};
	int *factories[] = {
		(int []){1, 1},
		(int []){3, 1},
	};
	long long dist = minimumTotalDistance(
		robots, ARRAY_LEN(robots),
		factories, ARRAY_LEN(factories), NULL
	);

	printf("dist: %lld\n", dist);
	printf("\n");
}

int
main(void)
{
	example1();
	example2();
	custom1();

	return 0;
}

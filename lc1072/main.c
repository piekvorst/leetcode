#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof((x)[0]))

int
maxEqualRowsAfterFlips(int **matrix, int rows, int *cols);

void
example1(void)
{
	printf("main.c:/example1/\n");

	int *arr[] = {
		(int []){0, 1},
		(int []){1, 1},
	};
	int equalrows = maxEqualRowsAfterFlips(
		arr, nelem(arr),
		(int []){2, 2}
	); // 1

	printf("equalrows: %d\n", equalrows);
	printf("\n");
}

void
example2(void)
{
	printf("main.c:/example2/\n");

	int *arr[] = {
		(int []){0, 1},
		(int []){1, 0},
	};
	int equalrows = maxEqualRowsAfterFlips(
		arr, nelem(arr),
		(int []){2, 2}
	); // 2

	printf("equalrows: %d\n", equalrows);
	printf("\n");
}

void
example3(void)
{
	printf("main.c:/example3/\n");

	int *arr[] = {
		(int []){0, 0, 0},
		(int []){0, 0, 1},
		(int []){1, 1, 0},
	};
	int equalrows = maxEqualRowsAfterFlips(
		arr, nelem(arr),
		(int []){3, 3, 3}
	); // 2

	printf("equalrows: %d\n", equalrows);
	printf("\n");
}

void
custom1(void)
{
	printf("main.c:/custom1/\n");

	int *arr[] = {
		(int []){0, 1, 0},
		(int []){0, 1, 0},
		(int []){1, 1, 0},
	};
	int equalrows = maxEqualRowsAfterFlips(
		arr, nelem(arr),
		(int []){3, 3, 3}
	); // 2

	printf("equalrows: %d\n", equalrows);
	printf("\n");
}

void
custom2(void)
{
	printf("main.c:/custom2/\n");

	int *arr[] = {
		(int []){0, 1, 0, 0},
		(int []){1, 0, 1, 1},
		(int []){0, 1, 0, 0},
		(int []){0, 1, 1, 0},
	};
	int equalrows = maxEqualRowsAfterFlips(
		arr, nelem(arr),
		(int []){4, 4, 4, 4}
	); // 3

	printf("equalrows: %d\n", equalrows);
	printf("\n");
}

void
wronganswer1(void)
{
	printf("main.c:/wronganswer1/\n");

	int *arr[] = {
		(int []){1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1},
		(int []){1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
		(int []){1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1},
		(int []){1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
		(int []){1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},
	};
	int equalrows = maxEqualRowsAfterFlips(
		arr, nelem(arr),
		(int []){11, 11, 11, 11, 11}
	); // 2

	printf("equalrows: %d\n", equalrows);
	printf("\n");
}

void
wronganswer2(void)
{
	printf("main.c:/wronganswer2/\n");

	int *arr[] = {
		(int []){1, 1, 1, 0, 1, 1, 0},
		(int []){0, 1, 0, 1, 1, 0, 0},
		(int []){1, 1, 0, 1, 0, 1, 0},
		(int []){1, 0, 0, 0, 0, 1, 1},
		(int []){0, 1, 1, 0, 0, 1, 1},
		(int []){1, 0, 0, 0, 1, 1, 0},
		(int []){0, 1, 0, 1, 0, 1, 0},
		(int []){1, 0, 0, 1, 0, 1, 0},
		(int []){0, 1, 0, 1, 0, 1, 1},
		(int []){1, 1, 1, 1, 1, 1, 0},
	};
	int equalrows = maxEqualRowsAfterFlips(
		arr, nelem(arr),
		(int []){7, 7, 7, 7, 7, 7, 7, 7, 7, 7}
	); // 1

	printf("equalrows: %d\n", equalrows);
	printf("\n");
}

int
main(void)
{
	example1();
	example2();
	example3();
	custom1();
	custom2();
	wronganswer1();
	wronganswer2();

	return 0;
}

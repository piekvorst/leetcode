#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof((x)[0]))

long long
maxMatrixSum(int **matrix, int rows, int *cols);

void
example1(void)
{
	printf("main.c:/example1/\n");

	int *arr[] = {
		(int []){1, -1},
		(int []){-1, 1},
	};
	int sum = maxMatrixSum(
		arr, nelem(arr),
		(int []){2, 2}
	); // 4

	printf("sum: %d\n", sum);
	printf("\n");
}

void
example2(void)
{
	printf("main.c:/example2/\n");

	int *arr[] = {
		(int []){1, 2, 3},
		(int []){-1, -2, -3},
		(int []){1, 2, 3},
	};
	int sum = maxMatrixSum(
		arr, nelem(arr),
		(int []){3, 3, 3}
	); // 16

	printf("sum: %d\n", sum);
	printf("\n");
}

void
wronganswer1(void)
{
	printf("main.c:/wronganswer1/\n");

	int *arr[] = {
		(int []){-1, 0, -1},
		(int []){-2, 1, 3},
		(int []){3, 2, 2},
	};
	int sum = maxMatrixSum(
		arr, nelem(arr),
		(int []){3, 3, 3}
	); // 15

	printf("sum: %d\n", sum);
	printf("\n");
}

void
wronganswer2(void)
{
	printf("main.c:/wronganswer2/\n");

	int *arr[] = {
		(int []){-3, 0, 0},
		(int []){0, 0, 0},
		(int []){0, 3, 2},
	};
	int sum = maxMatrixSum(
		arr, nelem(arr),
		(int []){3, 3, 3}
	); // 8

	printf("sum: %d\n", sum);
	printf("\n");
}

void
wronganswer3(void)
{
	printf("main.c:/wronganswer3/\n");

	int *arr[] = {
		(int []){9, -3, -4},
		(int []){-4, -1, -3},
		(int []){-6, -3, -3},
	};
	int sum = maxMatrixSum(
		arr, nelem(arr),
		(int []){3, 3, 3}
	); // 36

	printf("sum: %d\n", sum);
	printf("\n");
}

void
wronganswer4(void)
{
	printf("main.c:/wronganswer4/\n");

	int *arr[] = {
		(int []){2, 9, 3},
		(int []){5, 4, -4},
		(int []){1, 7, 1},
	};
	int sum = maxMatrixSum(
		arr, nelem(arr),
		(int []){3, 3, 3}
	); // 34

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
	wronganswer3();
	wronganswer4();

	return 0;
}

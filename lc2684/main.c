#include <stdio.h>

#define nelem(arr) (sizeof(arr) / sizeof((arr)[0]))

int
maxMoves(int **grid, int nrow, int *ncol);

void
example1(void)
{
	printf("main.c:/example1/\n");

	int *grid[] = {
		(int []){2, 4, 3, 5},
		(int []){5, 4, 9, 3},
		(int []){3, 4, 2, 11},
		(int []){10, 9, 13, 15},
	};
	int m = maxMoves(
		grid, nelem(grid),
		(int []){4, 4, 4, 4}
	); // 3

	printf("maxMoves: %d\n", m);
	printf("\n");
}

void
example2(void)
{
	printf("main.c:/example2/\n");

	int *grid[] = {
		(int []){3, 2, 4},
		(int []){2, 1, 9},
		(int []){1, 1, 7},
	};
	int m = maxMoves(
		grid, nelem(grid),
		(int []){3, 3, 3}
	); // 0

	printf("maxMoves: %d\n", m);
	printf("\n");
}

void
custom1(void)
{
	printf("main.c:/custom1/\n");

	int *grid[] = {
		(int []){2, 4, 3, 5},
		(int []){5, 4, 9, 3},
		(int []){3, 4, 2, 8},
		(int []){10, 9, 13, 12},
	};
	int m = maxMoves(
		grid, nelem(grid),
		(int []){4, 4, 4, 4}
	); // 2

	printf("maxMoves: %d\n", m);
	printf("\n");
}

void
wronganswer1(void)
{
	printf("main.c:/wronganswer1/\n");

	int *grid[] = {
		(int []){270, 192, 213, 26, 270},
		(int []){288, 99, 1, 136, 98},
		(int []){143, 168, 117, 127, 38},
		(int []){193, 218, 16, 61, 216},
		(int []){59, 224, 106, 9, 144},
		(int []){253, 166, 202, 132, 281},
		(int []){233, 197, 253, 98, 36},
		(int []){105, 289, 255, 277, 98},
		(int []){247, 125, 15, 275, 35},
		(int []){208, 76, 147, 22, 124},
		(int []){198, 245, 6, 167, 105},
		(int []){28, 100, 15, 84, 300},
		(int []){197, 263, 2, 251, 155},
		(int []){87, 41, 216, 91, 112},
		(int []){263, 32, 225, 102, 298},
	};
	int m = maxMoves(
		grid, nelem(grid),
		(int []){5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5}
	); // 4

	printf("maxMoves: %d\n", m);
	printf("\n");
}

int
main(void)
{
	example1();
	example2();
	custom1();
	wronganswer1();

	return 0;
}

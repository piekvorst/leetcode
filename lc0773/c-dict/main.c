#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof((x)[0]))

int
slidingPuzzle(int **board, int rows, int *cols);

void
example1(void)
{
	printf("main.c:/example1/\n");

	int *board[] = {
		(int []){1, 2, 3},
		(int []){4, 0, 5},
	};
	int moves = slidingPuzzle(
		board, nelem(board),
		(int []){3, 3}
	); // 1

	printf("moves: %d\n", moves);
	printf("\n");
}

void
example2(void)
{
	printf("main.c:/example2/\n");

	int *board[] = {
		(int []){1, 2, 3},
		(int []){5, 4, 0},
	};
	int moves = slidingPuzzle(
		board, nelem(board),
		(int []){3, 3}
	); // -1

	printf("moves: %d\n", moves);
	printf("\n");
}

void
example3(void)
{
	printf("main.c:/example3/\n");

	int *board[] = {
		(int []){4, 1, 2},
		(int []){5, 0, 3},
	};
	int moves = slidingPuzzle(
		board, nelem(board),
		(int []){3, 3}
	); // 5

	printf("moves: %d\n", moves);
	printf("\n");
}

void
wronganswer1(void)
{
	printf("main.c:/wronganswer1/\n");

	int *board[] = {
		(int []){3, 2, 4},
		(int []){1, 5, 0},
	};
	int moves = slidingPuzzle(
		board, nelem(board),
		(int []){3, 3}
	); // 14

	printf("moves: %d\n", moves);
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

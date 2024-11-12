#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof((x)[0]))

int *
maximumBeauty(int **items, int nitems, int *mitems, int *queries, int nqueries, int *nanswer);

void
arrprint
	(int *p, int len)
{
	for (int *q = p; q != p+len; ++q)
		printf("	%d", *q);

	printf("\n");
}

void
example1(void)
{
	printf("main.c:/example1/\n");

	int *items[] = {
		(int []){1, 2},
		(int []){3, 2},
		(int []){2, 4},
		(int []){5, 6},
		(int []){3, 5},
	};
	int queries[] = {1, 2, 3, 4, 5, 6};

	int nanswer = 0;
	int *answer = maximumBeauty(
		items, nelem(items), NULL,
		queries, nelem(queries),
		&nanswer
	); // 2, 4, 5, 5, 6, 6

	arrprint(answer, nanswer);
	printf("\n");
}

void
example2(void)
{
	printf("main.c:/example2/\n");

	int *items[] = {
		(int []){1, 2},
		(int []){1, 2},
		(int []){1, 3},
		(int []){1, 4},
	};
	int queries[] = {1};

	int nanswer = 0;
	int *answer = maximumBeauty(
		items, nelem(items), NULL,
		queries, nelem(queries),
		&nanswer
	); // 4

	arrprint(answer, nanswer);
	printf("\n");
}

void
example3(void)
{
	printf("main.c:/example3/\n");

	int *items[] = {
		(int []){10, 1000},
	};
	int queries[] = {5};

	int nanswer = 0;
	int *answer = maximumBeauty(
		items, nelem(items), NULL,
		queries, nelem(queries),
		&nanswer
	); // 0

	arrprint(answer, nanswer);
	printf("\n");
}

int
main(void)
{
	example1();
	example2();
	example3();

	return 0;
}

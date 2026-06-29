#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof((x)[0]))

int
numOfStrings(char **patterns, int npatterns, char* word);

void
example1(void)
{
	printf("main.c:/example1/\n");

	char *patterns[] = {"a", "abc", "bc", "d"};
	int got = numOfStrings(patterns, nelem(patterns), "abc"); // 3

	printf("%d\n", got);
	printf("\n");
}

void
example2(void)
{
	printf("main.c:/example2/\n");

	char *patterns[] = {"a", "b", "c"};
	int got = numOfStrings(patterns, nelem(patterns), "aaaaabbbbb"); // 2

	printf("%d\n", got);
	printf("\n");
}

void
example3(void)
{
	printf("main.c:/example3/\n");

	char *patterns[] = {"a", "a", "a"};
	int got = numOfStrings(patterns, nelem(patterns), "ab"); // 3

	printf("%d\n", got);
	printf("\n");
}

void
wronganswer1(void)
{
	char *patterns[] = {
		"glgpqusg",

		// contains
		"qsyrgdelg",

		"akcsg",

		// contains
		"e",

		"fnmi",

		// contains
		"gzqsyrgdelg",

		"lapwypxrmaydjr",

		// contains
		"s",

		// contains
		"iwig",
	};
	int got = numOfStrings(patterns, nelem(patterns), "numiwigzqsyrgdelgxs"); // 5

	printf("main.c:/wronganswer1/\n");
	printf("%d\n", got);
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

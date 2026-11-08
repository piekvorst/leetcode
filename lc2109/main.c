#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof((x)[0]))

char *
addSpaces(char *s, int *spaces, int nspaces);

void
example1(void)
{
	printf("main.c:/example1/\n");

	int spaces[] = {8, 13, 15};
	char *withspaces = addSpaces(
		"LeetcodeHelpsMeLearn",
		spaces, nelem(spaces)
	); // "Leetcode Helps Me Learn"

	printf("%s\n", withspaces);
	printf("\n");
}

void
example2(void)
{
	printf("main.c:/example2/\n");

	int spaces[] = {1, 5, 7, 9};
	char *withspaces = addSpaces(
		"icodeinpython",
		spaces, nelem(spaces)
	); // "i code in py thon"

	printf("%s\n", withspaces);
	printf("\n");
}

void
example3(void)
{
	printf("main.c:/example3/\n");

	int spaces[] = {0, 1, 2, 3, 4, 5, 6};
	char *withspaces = addSpaces(
		"spacing",
		spaces, nelem(spaces)
	); // " s p a c i n g"

	printf("%s\n", withspaces);
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

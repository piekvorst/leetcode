#include <stdio.h>

#define MIN(x, y) ((x)<(y) ? (x) : (y))

int
takeCharacters(char *s, int k);

void
example1(void)
{
	printf("main.c:/example1/\n");

	int minutes = takeCharacters("aabaaaacaabc", 2); // 8

	printf("minutes: %d\n", minutes);
	printf("\n");
}

void
example2(void)
{
	printf("main.c:/example2/\n");

	int minutes = takeCharacters("a", 1); // -1

	printf("minutes: %d\n", minutes);
	printf("\n");
}

void
wronganswer1(void)
{
	printf("main.c:/wronganswer1/\n");

	int minutes = takeCharacters("a", 0); // 0

	printf("minutes: %d\n", minutes);
	printf("\n");
}

void
wronganswer2(void)
{
	printf("main.c:/wronganswer2/\n");

	int minutes = takeCharacters("abc", 1); // 3

	printf("minutes: %d\n", minutes);
	printf("\n");
}

void
wronganswer3(void)
{
	printf("main.c:/wronganswer3/\n");

	int minutes = takeCharacters("bcca", 1); // 3

	printf("minutes: %d\n", minutes);
	printf("\n");
}

void
wronganswer4(void)
{
	printf("main.c:/wronganswer4/\n");

	int minutes = takeCharacters("acba", 1); // 3

	printf("minutes: %d\n", minutes);
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

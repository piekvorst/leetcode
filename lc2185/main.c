#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof((x)[0]))

int
prefixCount(char **words, int nwords, char *pref);

void
example1(void)
{
	printf("main.c:/example1/\n");

	char *words[] = {"pay", "attention", "practice", "attend"};
	int n = prefixCount(words, nelem(words), "at"); // 2

	printf("n: %d\n", n);
	printf("\n");
}

void
example2(void)
{
	printf("main.c:/example2/\n");

	char *words[] = {"leetcode", "win", "loops", "success"};
	int n = prefixCount(words, nelem(words), "code"); // 0

	printf("n: %d\n", n);
	printf("\n");
}

int
main(void)
{
	example1();
	example2();

	return 0;
}

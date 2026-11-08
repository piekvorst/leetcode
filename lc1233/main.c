#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof((x)[0]))

char **
removeSubfolders(char **folder, int nfolder, int *nout);

void
example1(void)
{
	printf("main.c:/example1/\n");

	char *str[] = {
		 "/a",
		 "/a/b",
		 "/c/d",
		 "/c/d/e",
		 "/c/f",
	};

	int n = 0;
	char **arr = removeSubfolders(str, nelem(str), &n);

	for (char **p = arr; p != arr+n; ++p)
		printf("%s\n", *p);
	printf("\n");
}

void
example2(void)
{
	printf("main.c:/example2/\n");

	char *str[] = {
		 "/a",
		 "/a/b/c",
		 "/a/b/d"
	};

	int n = 0;
	char **arr = removeSubfolders(str, nelem(str), &n);

	for (char **p = arr; p != arr+n; ++p)
		printf("%s\n", *p);
	printf("\n");
}

void
example3(void)
{
	printf("main.c:/example3/\n");

	char *str[] = {
		 "/a/b/c",
		 "/a/b/ca",
		 "/a/b/d"
	};

	int n = 0;
	char **arr = removeSubfolders(str, nelem(str), &n);

	for (char **p = arr; p != arr+n; ++p)
		printf("%s\n", *p);
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

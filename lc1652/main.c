#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof((x)[0]))

int *
decrypt(int *code, int len, int k, int *nout);

void
arrprint(int *p, int len)
{
	for (int *pp = p; pp != p+len; ++pp)
		printf("\t%d", *pp);

	printf("\n");
}

void
example1(void)
{
	printf("main.c:/example1/\n");

	int code[] = {5, 7, 1, 4};

	int ndecrypted = 0;
	int *decrypted = decrypt(code, nelem(code), 3, &ndecrypted);

	printf("decrypted:\n");
	arrprint(decrypted, ndecrypted); // 12, 10, 16, 13
	printf("\n");
}

void
example2(void)
{
	printf("main.c:/example2/\n");

	int code[] = {1, 2, 3, 4};

	int ndecrypted = 0;
	int *decrypted = decrypt(code, nelem(code), 0, &ndecrypted);

	printf("decrypted:\n");
	arrprint(decrypted, ndecrypted); // 0, 0, 0, 0
	printf("\n");
}

void
example3(void)
{
	printf("main.c:/example3/\n");

	int code[] = {2, 4, 9, 3};

	int ndecrypted = 0;
	int *decrypted = decrypt(code, nelem(code), -2, &ndecrypted);

	printf("decrypted:\n");
	arrprint(decrypted, ndecrypted); // 12, 5, 6, 13
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

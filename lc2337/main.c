#include <stdbool.h>
#include <stdio.h>

void
example1(void)
{
	printf("main.c:/example1/\n");

	bool ok = canChange("_L__R__R_", "L______RR"); // 1

	printf("ok: %d\n", ok);
	printf("\n");
}

void
example2(void)
{
	printf("main.c:/example2/\n");

	bool ok = canChange("R_L_", "__LR"); // 0

	printf("ok: %d\n", ok);
	printf("\n");
}

void
example3(void)
{
	printf("main.c:/example3/\n");

	bool ok = canChange("_R", "R_"); // 0

	printf("ok: %d\n", ok);
	printf("\n");
}

void
wronganswer1(void)
{
	printf("main.c:/wronganswer1/\n");

	bool ok = canChange("____", "R_L_"); // 0

	printf("ok: %d\n", ok);
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

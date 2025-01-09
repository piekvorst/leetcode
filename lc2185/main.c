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

void
wronganswer1(void)
{
	printf("main.c:/wronganswer1/\n");

	char *words[] = {"lewsmb", "lewrydnve", "lewqqm", "lewec", "lewn", "lewb", "lewedb"};
	int n = prefixCount(words, nelem(words), "lew"); // 7

	printf("n: %d\n", n);
	printf("\n");
}

void
wronganswer2(void)
{
	printf("main.c:/wronganswer2/\n");

	char *words[] = {
		"kttxeksggb", "vucqwew", "lyknscc", "mryl", "vwarnwkfmd",
		"ivawxbntgs", "mylw", "namybmfy", "uosag", "rzernqxyn", "puf",
		"hfwjnmvm", "jjfyd", "xteybd", "v", "ywntwzn", "npsogop",
		"brgvlw", "vewhi", "brk", "hheub", "zl", "vt", "bxjtjivep", "p",
		"io", "xotulskjmt", "mctffonh", "pmeuqhoe", "ghktrtq", "u",
		"ngnvwan", "pqmlvvhl", "enjf", "qomcejb", "twgqww", "bnilyqy",
		"nc", "fttlodnz", "fya", "g", "uoivsr", "gtxgcaf", "qs", "gkfl",
		"sdmacxf", "mzy", "xjv", "yipc", "rctqugjjk", "myij", "xxg",
		"vyup", "utqxplpsa", "imbteaczlc", "qfgdcz", "atfn", "pxcsg", "f",
		"omukbiaudb", "uh", "uobwgt", "hgqipk", "zunfzinenk", "i", "p",
		"pet", "fxai", "ortqpwkukg", "rxgh", "ylfh",
	};
	int n = prefixCount(words, nelem(words), "ikwjoty"); // 0

	printf("n: %d\n", n);
	printf("\n");
}

int
main(void)
{
	example1();
	example2();
	wronganswer1();
	wronganswer2();

	return 0;
}

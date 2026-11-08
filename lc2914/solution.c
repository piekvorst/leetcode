#include <stdio.h>

void
printslice
	(char *p, char *q)
{
	for (char *r = p; r != q; ++r)
		printf("%c", *r);

	printf("\n");
}

int
minChanges
	(char *s)
{
	int changes = 0;
	int len = 1;
	char *p = s, *q = s + 1;
	while (*p && *q) {
		if (*p == *q) {
			++len, ++p, ++q;
			continue;
		}

		if (len % 2 == 0) {
			len = 1;
			++p, ++q;
			continue;
		}

		//printslice(s, q);
		//fflush(stdout);

		++changes;
		*q = *p;
		len = 1;
		p += 2;
		q += 2;
	}

	return changes;
}

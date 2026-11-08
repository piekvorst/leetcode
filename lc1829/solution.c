#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof((x)[0]))

int
maxxor
	(int n, int limit)
{
	int m = 0;
	for (int i = 0; i < limit; ++i) {
		if ((n ^ 1<<i) & 1<<i)
			m |= 1 << i;
	}
	return m;
}

int *
getMaximumXor
	(int *p, int plen, int exponent, int *qlen)
{
	int *q;
	q = calloc(plen, sizeof(*q));

	int xor = 0;

	int *s = q + plen - 1;
	for (int *r = p; r != p+plen; ++r) {
		xor ^= *r;
		*(s--) = maxxor(xor, exponent);
	}

	*qlen = plen;
	return q;
}

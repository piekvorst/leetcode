#include <stdlib.h>

int
numcmp(const void *vp1, const void *vp2)
{
	int x = *(int *)vp1;
	int y = *(int *)vp2;

	return (x > y) - (x < y);
}

long long
countFairPairs(int *p, int len, int lower, int upper)
{
	qsort(p, len, sizeof(*p), numcmp);

	long long pairs = 0;

	for (int *pp = p; pp != p+len; ++pp) {

		// left is the smallest in [pp+1; p+len) at which *pp+*left >= lower
		int *left = pp+1, *limit = p+len;
		while (left < limit) {
			int *h = left + (limit - left)/2;
			if (!(*pp+*h >= lower))
				left = h + 1;
			else
				limit = h;
		}

		if (left == p+len || !(*pp+*left >= lower))
			continue;

		// right is the smallest in [pp+1; p+len) at which *pp+*right > upper
		int *right = pp+1;
		limit = p + len;
		while (right < limit) {
			int *h = right + (limit - right)/2;
			if (!(*pp+*h > upper))
				right = h + 1;
			else
				limit = h;
		}

		pairs += right - left;
	}

	return pairs;
}

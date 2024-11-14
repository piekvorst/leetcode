#include <stdbool.h>

#define MAX(x, y) ((x)>(y) ? (x) : (y))
#define MIN(x, y) ((x)<(y) ? (x) : (y))

bool
candistribute(int x, int n, int *quantities, int qlen)
{
	for (int *qp = quantities; qp != quantities+qlen; ++qp) {
		int q = *qp;
		while (q) {
			if (n == 0)
				return false;

			q -= MIN(x, q);
			--n;
		}
	}

	return true;
}

int
minimizedMaximum(int n, int *quantities, int qlen)
{
	int maxq = 0;
	for (int *qp = quantities; qp != quantities+qlen; ++qp)
		maxq = MAX(maxq, *qp);

	// x is the smallest in [0; max(quantities)) at which candistribute(x) is true
	int x = 0, limit = maxq;
	while (x < limit) {
		int h = (x + limit) / 2;
		if (!candistribute(h, n, quantities, qlen))
			x = h + 1;
		else
			limit = h;
	}

	return x;
}

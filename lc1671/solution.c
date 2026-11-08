#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MIN(x, y) ((x)<(y) ? (x) : (y))

void
dbg(int *arr, int narr)
{
	for (int *p = arr; p != arr+narr; ++p)
		printf("	%d", *p);

	printf("\n");
}

bool
validMountainArray(int *arr, int narr)
{
	if (narr < 3)
		return false;

	int *p = arr, *q = arr + 1;
	if (*p > *q)
		return false;

	while (q != arr + narr && *p < *q)
		p++, q++;

	if (q == arr + narr)
		return false;

	while (q != arr + narr && *p > *q)
		p++, q++;

	return q == arr + narr;
}

int
dfs(
	int *arr, int narr,

	int *buf, int nbuf,
	int removed,
	int i, bool keep
)
{
	if (i == narr) {
		if (validMountainArray(buf, nbuf))
			return removed;
		else
			return -1;
	}

	if (keep)
		buf[nbuf++] = arr[i];
	else
		++removed;

	int trykeep = dfs(arr, narr, buf, nbuf, removed, i+1, true);
	int tryremove = dfs(arr, narr, buf, nbuf, removed, i+1, false);

	if (trykeep == -1)
		return tryremove;
	else if (tryremove == -1)
		return trykeep;
	else
		return MIN(trykeep, tryremove);
}

int
minimumMountainRemovals(int *arr, int narr)
{
	int *buf;
	buf = calloc(narr, sizeof(*buf));

	int trykeep = dfs(arr, narr, buf, 0, 0, 0, true);
	int tryrm = dfs(arr, narr, buf, 0, 0, 0, true);

	if (trykeep == -1)
		return tryrm;
	else if (tryrm == -1)
		return trykeep;
	else
		return MIN(trykeep, tryrm);
}

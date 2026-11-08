#include <stdbool.h>

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

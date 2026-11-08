#include <stdbool.h>

#define MAX(x, y) ((x)>(y) ? (x) : (y))

int
largestCombination
	(int *arr, int narr)
{
	int dict[32] = {0};

	for (int *p = arr; p != arr+narr; ++p) {
		for (int i = 0; i < 32; ++i) {
			if (*p & (1ll << i))
				++dict[i];
		}
	}

	int combination = 0;
	for (int *p = dict; p != dict+32; ++p)
		combination = MAX(combination, *p);

	return combination;
}

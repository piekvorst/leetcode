#include <stdbool.h>

#define MAX(x, y) ((x)>(y) ? (x) : (y))
#define MIN(x, y) ((x)<(y) ? (x) : (y))

int
bits
	(int n)
{
	int out = 0;

	while (n) {
		out += n & 1;
		n >>= 1;
	}

	return out;
}

bool
canSortArray
	(int *nums, int nnums)
{
	// min [p q) >= max prev

	// The initial value follows from a constraint: 1 <= nums[i] <= 2e8
	int prevMax = 0;

	for (int *p = nums; p != nums+nnums;) {

		int min = *p, max = *p;

		// q: the first after p that is bits(p) != bits(q)
		int *q = p + 1;

		while (q != nums+nnums && bits(*p) == bits(*q)) {
			min = MIN(min, *q);
			max = MAX(max, *q);
			++q;
		}

		if (min < prevMax)
			return false;

		prevMax = max;
		p = q;
	}

	return true;
}

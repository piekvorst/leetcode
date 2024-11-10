#define MIN(x, y) ((x)<(y) ? (x) : (y))

int
dictnum
	(int dict[32])
{
	int n = 0;
	for (int *p = dict; p != dict+32; ++p) {
		n <<= 1;
		if (*p)
			n |= 1;
	}
	return n;
}

void
dictadd
	(int dict[32], int n)
{
	int *p = dict + 32 - 1;
	for (int i = 0; i < 32; ++i, --p) {
		if (n & 1)
			++*p;
		n >>= 1;
	}
}

void
dictremove
	(int dict[32], int n)
{
	int *p = dict + 32 - 1;
	for (int i = 0; i < 32; ++i, --p) {
		if (n & 1)
			--*p;
		n >>= 1;
	}
}

int
minimumSubarrayLength
	(int *p, int len, int k)
{
	int minlen = 200001;

	int *left = p, *right = p+1;
	int dict[32] = {0};
	dictadd(dict, *left);

	while (left < right) {
		if (dictnum(dict) < k) {
			if (right == p+len)
				goto stop;

			dictadd(dict, *right);
			++right;
		}
		if (dictnum(dict) >= k) {
			dictremove(dict, *left);
			++left;
			minlen = MIN(minlen, right - left);
		}
	}

stop:
	if (minlen == 200001)
		return -1;
	else
		return minlen + 1;
}

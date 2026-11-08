#define MIN(x, y) ((x)<(y) ? (x) : (y))

int
takeCharacters(char *s, int k)
{
	int a = 0, b = 0, c = 0;

	char *end = s;
	while (*end) {
		if (*end == 'a') ++a;
		else if (*end == 'b') ++b;
		else if (*end == 'c') ++c;

		++end;
	}

	if (a < k || b < k || c < k)
		return -1;

	int minutes = end - s;

	char *left = s, *right = end-1;
	int ldict[128] = {0}, rdict[128] = {0};

	// make right as wide as possible
	while (rdict['a'] < k || rdict['b'] < k || rdict['c'] < k)
		rdict[*(right--)]++;

	++right;

	while (left != end) {

		// each time left goes to the right, right goes to the right as well
		while (ldict[*right]+rdict[*right]-1 >= k)
			rdict[*(right++)]--;

		minutes = MIN(minutes, left-s + end-right);

		ldict[*(left++)]++;
	}

	return minutes;
}

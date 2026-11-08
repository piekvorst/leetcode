#include <stdlib.h>
#include <string.h>

#define MAX(x, y) ((x)>(y) ? (x) : (y))
#define NMEM 100001

struct entry
{
	int key, val;
	struct entry *next;
};
typedef struct entry Entry;

Entry *dict[NMEM];

Entry *
entrymk(int key, int val)
{
	Entry *e;
	e = calloc(1, sizeof(*e));

	e->key = key;
	e->val = val;

	return e;
}

Entry **
lookup(int key)
{
	Entry **e = &dict[key%NMEM];

	while (*e != NULL) {
		if ((*e)->key == key)
			return e;

		e = &(*e)->next;
	}

	return e;
}

long long
maximumSubarraySum(int *p, int len, int k)
{
	memset(dict, 0, sizeof(dict));

	long long sum = 0;
	long long maxsum = 0;
	int ndistinct = 0;

	for (int *pp = p; pp != p+k-1; ++pp) {
		Entry **e = lookup(*pp);
		if (!*e) {
			*e = entrymk(*pp, 1);
			++ndistinct;
		} else {
			(*e)->val++;
			if ((*e)->val == 2)
				--ndistinct;
		}

		sum += *pp;
	}

	int *r = p, *s = p+k-1;
	while (s != p+len) {

		// add *s
		sum += *s;
		Entry **e = lookup(*s);
		if (!*e) {
			*e = entrymk(*s, 1);
			++ndistinct;
		} else {
			(*e)->val++;
			if ((*e)->val == 2)
				--ndistinct;
		}

		if (ndistinct == k)
			maxsum = MAX(maxsum, sum);

		// remove *r
		sum -= *r;
		e = lookup(*r);
		if ((*e)->val == 1) {
			*e = (*e)->next;
			--ndistinct;
		} else {
			(*e)->val--;
			if ((*e)->val == 1)
				++ndistinct;
		}

		++r;
		++s;
	}

	return maxsum;
}

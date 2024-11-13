#include <stdio.h>
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

int
cmpitems(const void *vp1, const void *vp2)
{
	int *x = *(int **)vp1;
	int *y = *(int **)vp2;

	if (x[0] < y[0])
		return -1;
	else if (x[0] > y[0])
		return 1;
	else if (x[1] < y[1])
		return -1;
	else if (x[1] > y[1])
		return 1;
	else
		return 0;
}

int *
maximumBeauty(int **items, int nitems, int *mitems, int *queries, int nqueries, int *nanswer)
{
	memset(dict, 0, sizeof(dict));

	qsort(items, nitems, sizeof(*items), cmpitems);

	int *answer;
	answer = calloc(nqueries, sizeof(*answer));

	int *ap = answer;

	for (int *qp = queries; qp != queries+nqueries; ++qp) {
		Entry **e = lookup(*qp);
		if (*e) {
			*(ap++) = (*e)->val;
			continue;
		}

		// ip is the smallest on [items; items+nitems) at which (*ip)[0] > *qp
		int **ip = items, **limit = items+nitems;
		while (ip < limit) {
			int **h = ip + (limit - ip)/2;
			if (!((*h)[0] > *qp))
				ip = h + 1;
			else
				limit = h;
		}

		// make (*ip)[0] <= *qp
		--ip;

		int beauty = 0;
		for (; ip != items-1; --ip) {
			Entry **e = lookup((*ip)[0]);
			if (*e) {
				beauty = MAX(beauty, (*e)->val);
				break;
			}

			beauty = MAX(beauty, (*ip)[1]);
		}

		*lookup(*qp) = entrymk(*qp, beauty);
		*(ap++) = beauty;
	}

	*nanswer = nqueries;
	return answer;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(x, y) ((x)>(y) ? (x) : (y))
#define NMEM 100001

int (*mem[NMEM])[2];

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
	memset(mem, 0, sizeof(mem));

	qsort(items, nitems, sizeof(*items), cmpitems);

	int *answer;
	answer = calloc(nqueries, sizeof(*answer));

	int *ap = answer;

	for (int *qp = queries; qp != queries+nqueries; ++qp) {
		int (*bucket)[2] = mem[*qp%NMEM];
		if (bucket) {
			for (int (*bp)[2] = bucket; *bp; ++bp) {
//				printf("FOO\n");
				if ((*bp)[0] == *qp) {
					*(ap++) = (*bp)[1];
					goto nextquery;
				}
			}
		}

		// i is the smallest items[i] at which items[i][0] > *qp
		int i = 0, j = nitems;
		while (i < j) {
			int h = (i + j) / 2;
			if (!(items[h][0] > *qp))
				i = h + 1;
			else
				j = h;
		}

		int beauty = 0;

		int **ip = items + i - 1;
		for (int j = i - 1; j >= 0; --j, --ip) {
			int (*bucket)[2] = mem[(*ip)[0]%NMEM];
			if (bucket) {
				for (int (*bp)[2] = bucket; *bp; ++bp) {
//					printf("BAR\n");
					if ((*bp)[0] == (*ip)[0]) {
						beauty = MAX(beauty, (*bp)[1]);
						goto catchbeauty;
					}
				}
			}

			beauty = MAX(beauty, (*ip)[1]);
		}

	catchbeauty:

		bucket = mem[*qp%NMEM];
		if (!bucket)
			bucket = mem[*qp%NMEM] = calloc(10, sizeof(*bucket));
		int (*bp)[2] = bucket;
		while ((*bp)[0]) {
//			printf("BAZ\n");
			++bp;
		}
		(*bp)[0] = *qp;
		(*bp)[1] = beauty;

		*(ap++) = beauty;

	nextquery:
		;
	}

	*nanswer = nqueries;
	return answer;
}

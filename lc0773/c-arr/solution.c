#include <limits.h>
#include <stdbool.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof((x)[0]))
#define MIN(x, y) ((x)<(y) ? (x) : (y))

bool seenmem[6][6][6][6][6][6];
int movesmem[6][6][6][6][6][6];

int dirs[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

bool *
seen(int **b)
{
	return &seenmem[b[0][0]][b[0][1]][b[0][2]][b[1][0]][b[1][1]][b[1][2]];
}

int *
moves(int **b)
{
	return &movesmem[b[0][0]][b[0][1]][b[0][2]][b[1][0]][b[1][1]][b[1][2]];
}

void
dfs(int **b, int movesdone)
{
	if (*seen(b))
		return;

	if (*moves(b) && movesdone >= *moves(b))
		return;
	else
		*moves(b) = movesdone + 1;

	*seen(b) = true;

	int i, j;

	for (int k = 0; k < 2; ++k) {
		for (int l = 0; l < 3; ++l) {
			if (b[k][l] == 0) {
				i = k;
				j = l;
			}
		}
	}

	for (int (*dir)[2] = dirs; dir != dirs+nelem(dirs); ++dir) {
		int ii = i + (*dir)[0], jj = j + (*dir)[1];
		if (ii < 0 || ii >= 2 || jj < 0 || jj >= 3)
			continue;

		int *src = &b[i][j], *dst = &b[ii][jj];
		int tmp = *src; *src = *dst; *dst = tmp;

		dfs(b, movesdone+1);

		tmp = *src; *src = *dst; *dst = tmp;
	}

	*seen(b) = false;
}

int
slidingPuzzle(int **board, int rows, int *cols)
{
	memset(seenmem, 0, sizeof(seenmem));
	memset(movesmem, 0, sizeof(movesmem));

	dfs(board, 0);

	return movesmem[1][2][3][4][5][0] - 1;
}

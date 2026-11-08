#include <string.h>

#define MAX(x, y) ((x)>(y) ? (x) : (y))

int memo[100000];

// dfs returns the maximum number of moves performed from
// grid[i][j] to the end.
//
int
dfs(
	int **grid, int nrow, int ncol,

	int prev,
	int i, int j
)
{
	if (i < 0 || i >= nrow || j < 0 || j >= ncol || grid[i][j] <= prev)
		return 0;

	if (memo[i*31 + j])
		return memo[i*31 + j] - 1;

	int up = dfs(grid, nrow, ncol, grid[i][j], i-1, j+1);
	int still = dfs(grid, nrow, ncol, grid[i][j], i, j+1);
	int down = dfs(grid, nrow, ncol, grid[i][j], i+1, j+1);

	int moves = 1 + MAX(up, MAX(still, down));
	memo[i*31 + j] = 1 + moves;
	return moves;
}

int
maxMoves(int **grid, int nrow, int *ncol)
{
	memset(memo, 0, sizeof(memo));

	int moves = 0;
	for (int i = 0; i < nrow; i++) {
		int m = dfs(grid, nrow, ncol[0], 0, i, 0);
		moves = MAX(moves, m);
	}

	return moves - 1;
}

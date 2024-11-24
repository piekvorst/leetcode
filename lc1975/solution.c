#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

long long
maxMatrixSum(int **matrix, int rows, int *cols)
{
	int totalnegatives = 0;
	int minabs = INT_MAX;
	long long sum = 0;

	for (int **row = matrix; row != matrix+rows; ++row) {
		for (int *cell = *row; cell != *row+cols[0]; ++cell) {
			sum += abs(*cell);

			if (*cell < 0)
				++totalnegatives;

			if (abs(*cell) < minabs)
				minabs = abs(*cell);
		}
	}

	if (totalnegatives%2 != 0)
		sum -= 2 * minabs;

	return sum;
}

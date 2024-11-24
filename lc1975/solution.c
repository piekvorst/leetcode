#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

long long
maxMatrixSum(int **matrix, int rows, int *cols)
{
	int totalnegatives = 0;
	int totalzeroes = 0;
	int minabs = INT_MAX;
	int found = false;
	long long sum = 0;

	for (int **row = matrix; row != matrix+rows; ++row) {
		for (int *cell = *row; cell != *row+cols[0]; ++cell) {
			sum += abs(*cell);

			if (*cell < 0)
				++totalnegatives;
			if (*cell == 0)
				++totalzeroes;

			if (abs(*cell) < minabs) {
				if (found)
					sum += 2 * minabs;

				minabs = abs(*cell);
				sum -= 2 * abs(*cell);
				found = true;
			}
		}
	}

	if (found && (totalnegatives%2 == 0 || totalzeroes > 0))
		sum += 2 * minabs;

	return sum;
}

#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

long long
maxMatrixSum(int **matrix, int rows, int *cols)
{
	int totalnegatives = 0;
	int maxnegative = INT_MIN;
	int found = false;
	int sum = 0;

	for (int **row = matrix; row != matrix+rows; ++row) {
		for (int *cell = *row; cell != *row+cols[0]; ++cell) {
			sum += abs(*cell);

			if (*cell < 0)
				++totalnegatives;

			if (*cell < 0 && *cell > maxnegative) {
				if (found)
					sum += -maxnegative;

				maxnegative = *cell;
				sum -= 2 * abs(*cell);
				found = true;
			}
		}
	}

	if (totalnegatives%2 == 0)
		sum += 2 * abs(maxnegative);

	return sum;
}

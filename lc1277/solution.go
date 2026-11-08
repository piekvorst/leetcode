package lc1277

func countSquares(matrix [][]int) int {
	M := make([][]int, len(matrix))[:0]
	for _, sub := range matrix {
		arr := make([]int, len(sub))
		copy(arr, sub)
		M = append(M, arr)
	}

	for _, sub := range M {
		for i := 1; i < len(sub); i++ {
			if sub[i-1] != 0 && sub[i] == 1 {
				sub[i] = sub[i-1] + 1
			}
		}
	}

	out := 0

	for i := 0; i < len(M); i++ {
		for j := 0; j < len(M[i]); j++ {
			shortest := M[i][j]
			for k := 0; k < M[i][j]; k++ {
				if i-k < 0 {
					break
				}
				shortest = min(shortest, M[i-k][j])
				if k+1 > shortest {
					break
				}
				out++
			}
		}
	}

	return out
}

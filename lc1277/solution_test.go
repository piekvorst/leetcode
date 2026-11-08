package lc1277

import "testing"

func TestCountSquares(t *testing.T) {
	f := func(t *testing.T, name string, matrix [][]int, want int) {
		t.Helper()

		t.Run(name, func(t *testing.T) {
			t.Helper()

			if got := countSquares(matrix); got != want {
				t.Errorf("unexpected: %v", got)
			}
		})
	}

	f(t, "example1", [][]int{
		{0, 1, 1, 1},
		{1, 1, 1, 1},
		{0, 1, 1, 1},
	}, 15)

	f(t, "example2", [][]int{
		{1, 0, 1},
		{1, 1, 0},
		{1, 1, 0},
	}, 7)

	// transposed example1
	//
	f(t, "custom1", [][]int{
		{0, 1, 0},
		{1, 1, 1},
		{1, 1, 1},
		{1, 1, 1},
	}, 15)
}

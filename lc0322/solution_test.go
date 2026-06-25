package lc0322

import "testing"

func TestCoinChange(t *testing.T) {
	f := func(t *testing.T, name string, coins []int, amount, want int) {
		t.Helper()

		t.Run(name, func(t *testing.T) {
			t.Helper()

			if got := coinChange(coins, amount); got != want {
				t.Errorf("unexpected: %v", got)
			}
		})
	}

	f(t, "example1", []int{1, 2, 5}, 11, 3)

	f(t, "example2", []int{2}, 3, -1)

	f(t, "example3", []int{1}, 0, 0)

	f(t, "tle1", []int{1, 2, 5}, 100, 20)

	f(t, "tle2", []int{186, 419, 83, 408}, 6249, 20)
}

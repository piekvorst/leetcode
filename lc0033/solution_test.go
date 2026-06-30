package lc0033

import "testing"

func TestSearch(t *testing.T) {
	f := func(t *testing.T, name string, nums []int, target, want int) {
		t.Helper()

		t.Run(name, func(t *testing.T) {
			t.Helper()

			if got := search(nums, target); got != want {
				t.Errorf("unexpected: %v", got)
			}
		})
	}

	f(t, "example1", []int{4, 5, 6, 7, 0, 1, 2}, 0, 4)

	f(t, "example2", []int{4, 5, 6, 7, 0, 1, 2}, 3, -1)

	f(t, "example3", []int{1}, 0, -1)
}

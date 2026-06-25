package lc0228

import (
	"slices"
	"testing"
)

func TestLeastInterval(t *testing.T) {
	f := func(t *testing.T, name string, nums []int, want []string) {
		t.Helper()

		t.Run(name, func(t *testing.T) {
			t.Helper()

			if got := summaryRanges(nums); !slices.Equal(got, want) {
				t.Errorf("unexpected: %v", got)
			}
		})
	}

	f(t, "example1", []int{0, 1, 2, 4, 5, 7}, []string{"0->2", "4->5", "7"})

	f(t, "example2", []int{0, 2, 3, 4, 6, 8, 9}, []string{"0", "2->4", "6", "8->9"})
}

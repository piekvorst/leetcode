package lc1967

import "testing"

func TestNumOfStrings(t *testing.T) {
	f := func(t *testing.T, name string, patterns []string, word string, want int) {
		t.Helper()

		t.Run(name, func(t *testing.T) {
			t.Helper()

			if got := numOfStrings(patterns, word); got != want {
				t.Error("unexpected:", got)
			}
		})
	}

	f(t, "example1", []string{"a", "abc", "bc", "d"}, "abc", 3)
	f(t, "example2", []string{"a", "b", "c"}, "aaaaabbbbb", 2)
	f(t, "example3", []string{"a", "a", "a"}, "ab", 3)
}

package lc0003

import "testing"

func TestLengthOfLongestSubstring(t *testing.T) {
	f := func(t *testing.T, name, s string, want int) {
		t.Helper()

		t.Run(name, func(t *testing.T) {
			t.Helper()

			if got := lengthOfLongestSubstring(s); got != want {
				t.Errorf("unexpected: %v", got)
			}
		})
	}

	f(t, "example1", "abcabcbb", 3)

	f(t, "example2", "bbbbb", 1)

	f(t, "example3", "pwwkew", 3)
}

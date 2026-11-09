package q1

import (
	"testing"
)

func TestExample(t *testing.T) {
	f := func(t *testing.T, name string, n, T, want int) {
		t.Helper()

		t.Run(name, func(t *testing.T) {
			t.Helper()

			if got := smallestNumber(n, T); got != want {
				t.Errorf("unexpected number: %v", got)
			}
		})
	}

	f(t, "example1", 10, 2, 10)
	f(t, "example2", 15, 3, 16)
}

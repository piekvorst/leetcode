package lc0022

import (
	"slices"
	"testing"
)

func TestGenerateParenthesis(t *testing.T) {
	f := func(t *testing.T, name string, n int, want []string) {
		t.Helper()

		t.Run(name, func(t *testing.T) {
			t.Helper()

			if got := generateParenthesis(n); !slices.Equal(got, want) {
				t.Errorf("unexpected: %v", got)
			}
		})
	}

	f(t, "example1", 3, []string{"((()))", "(()())", "(())()", "()(())", "()()()"})

	f(t, "example2", 1, []string{"()"})
}

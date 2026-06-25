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

			got := generateParenthesis(n)

			gotsorted := slices.Clone(got)
			wantsorted := slices.Clone(want)

			slices.Sort(gotsorted)
			slices.Sort(wantsorted)

			if !slices.Equal(gotsorted, wantsorted) {
				t.Errorf("unexpected value: %v\nwanted: %v", gotsorted, wantsorted)
			}
		})
	}

	f(t, "example1", 3, []string{"((()))", "(()())", "(())()", "()(())", "()()()"})

	f(t, "example2", 1, []string{"()"})

	f(
		t,
		"wronganswer1",
		4,
		[]string{

			// 1 parent
			"(((())))", "((()()))", "((())())", "(()(()))", "(()()())",

			// 2 parents
			"((()))()", "(()())()", "(())(())", "()((()))", "()(()())",

			// 3 parents
			"(())()()",
			"()(())()",
			"()()(())",

			// 4 parents
			"()()()()",
		},
	)
}

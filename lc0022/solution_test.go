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

			gotcopy := slices.Clone(got)
			wantcopy := slices.Clone(want)

			slices.Sort(gotcopy)
			slices.Sort(wantcopy)

			if !slices.Equal(gotcopy, wantcopy) {
				t.Errorf("unexpected value: %v\nwanted: %v", gotcopy, wantcopy)
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

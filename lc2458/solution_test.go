package lc2458

import (
	"slices"
	"testing"
)

func TestTreeQueries(t *testing.T) {
	f := func(t *testing.T, name string, head *TreeNode, queries, want []int) {
		t.Helper()

		t.Run(name, func(t *testing.T) {
			t.Helper()

			if got := treeQueries(head, queries); !slices.Equal(got, want) {
				t.Errorf("got %v, want %v", got, want)
			}
		})
	}

	g := func(val int, left, right *TreeNode) *TreeNode {
		return &TreeNode{val, left, right}
	}

	f(
		t, "example1",
		g(
			1,
			g(3, g(2, nil, nil), nil),
			g(
				4,
				g(6, nil, nil),
				g(5, nil, g(7, nil, nil)),
			),
		),
		[]int{7},
		[]int{2},
	)
	f(
		t, "example2",
		g(
			5,
			g(
				8,
				g(2, g(4, nil, nil), g(6, nil, nil)),
				g(1, nil, nil),
			),
			g(9, g(3, nil, nil), g(7, nil, nil)),
		),
		[]int{3, 2, 4, 8},
		[]int{3, 2, 3, 2},
	)
}

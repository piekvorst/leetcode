package lc0002

import (
	"slices"
	"strconv"
	"testing"
)

func TestAddTwoNumbers(t *testing.T) {
	f := func(t *testing.T, name string, l1, l2, want *ListNode) {
		t.Helper()

		t.Run(name, func(t *testing.T) {
			t.Helper()

			if got := addTwoNumbers(l1, l2); !listsEqual(got, want) {
				t.Errorf("unexpected: %v", listString(got))
			}
		})
	}

	f(t, "example1", mklist(2, 4, 3), mklist(5, 6, 4), mklist(7, 0, 8))
	f(t, "example2", mklist(0), mklist(0), mklist(0))
	f(t, "example3", mklist(9, 9, 9, 9, 9, 9, 9), mklist(9, 9, 9, 9), mklist(8, 9, 9, 9, 0, 0, 0, 1))
}

func mklist(s ...int) *ListNode {
	var out *ListNode
	for _, v := range slices.Backward(s) {
		out = &ListNode{Val: v, Next: out}
	}
	return out
}

func listsEqual(l1, l2 *ListNode) bool {
	p1, p2 := l1, l2
	for p1 != nil && p2 != nil {
		if p1.Val != p2.Val {
			return false
		}
		p1, p2 = p1.Next, p2.Next
	}
	return p1 == nil && p2 == nil
}

func listString(l *ListNode) string {
	var out string

	p := l
	for p != nil {
		out += strconv.Itoa(p.Val) + "->"
		p = p.Next
	}

	out += "nil"
	return out
}

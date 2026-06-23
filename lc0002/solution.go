package lc0002

type ListNode struct {
	Val  int
	Next *ListNode
}

func addTwoNumbers(l1, l2 *ListNode) *ListNode {
	p1, p2 := l1, l2

	var out *ListNode
	op := &out

	carried := 0
	for p1 != nil || p2 != nil {

		var sum int

		switch {
		case p1 != nil && p2 != nil:
			sum = p1.Val + p2.Val + carried
			p1, p2 = p1.Next, p2.Next
		case p1 != nil:
			sum = p1.Val + carried
			p1 = p1.Next
		case p2 != nil:
			sum = p2.Val + carried
			p2 = p2.Next
		}

		carried = 0
		if sum > 9 {
			sum %= 10
			carried = 1
		}

		*op = &ListNode{Val: sum}
		op = &(*op).Next
	}

	if carried != 0 {
		*op = &ListNode{Val: 1}
	}

	return out
}

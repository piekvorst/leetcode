package lc2458

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

type extnode struct {
	Origin              *TreeNode
	Parent, Left, Right *extnode
	lheight, rheight    int
}

func (n *extnode) Lheight() int {
	if n == nil {
		return 0
	} else {
		return n.lheight
	}
}

func (n *extnode) Rheight() int {
	if n == nil {
		return 0
	} else {
		return n.rheight
	}
}

func makextree(head *TreeNode, parent *extnode, length *int) *extnode {
	if head == nil {
		return nil
	}

	(*length)++

	n := &extnode{}
	n.Origin = head
	n.Parent = parent
	n.Left = makextree(head.Left, n, length)
	n.Right = makextree(head.Right, n, length)
	return n
}

func evalheight(head *extnode) int {
	if head == nil {
		return 0
	}
	head.lheight = 1 + evalheight(head.Left)
	head.rheight = 1 + evalheight(head.Right)
	return max(head.lheight, head.rheight)
}

func extdict(head *extnode, dict []*extnode) {
	var dfs func(*extnode)
	dfs = func(head *extnode) {
		if head == nil {
			return
		}
		dict[head.Origin.Val] = head
		dfs(head.Left)
		dfs(head.Right)
	}
	dfs(head)
}

func evalgroundup(node *extnode) {
	for n := node; n != nil; n = n.Parent {
		n.lheight = 1 + max(n.Left.Lheight(), n.Left.Rheight())
		n.rheight = 1 + max(n.Right.Lheight(), n.Right.Rheight())
	}
}

func treeQueries(head *TreeNode, queries []int) []int {
	heights := make([]int, len(queries))[:0]

	nodelen := 0
	xhead := makextree(head, nil, &nodelen)
	evalheight(xhead)

	dict := make([]*extnode, nodelen+1)
	extdict(xhead, dict)

	for _, q := range queries {
		buf := *dict[q]

		dict[q].lheight, dict[q].rheight = 0, 0
		evalgroundup(dict[q].Parent)

		heights = append(heights, max(xhead.lheight, xhead.rheight)-1)

		*dict[q] = buf
		evalgroundup(dict[q].Parent)
	}

	return heights
}

func main() {
	test := func(head *TreeNode, queries []int) {
		fmt.Printf("input: %v... %v...\n", head.Val, queries[0])
		out := treeQueries(head, queries)
		fmt.Printf("output: %v\n", out)
	}

	f := func(val int, left, right *TreeNode) *TreeNode {
		return &TreeNode{val, left, right}
	}
	test(f(1, f(3, f(2, nil, nil), nil), f(4, f(6, nil, nil), f(5, nil, f(7, nil, nil)))), []int{7})
	test(f(5, f(8, f(2, f(4, nil, nil), f(6, nil, nil)), f(1, nil, nil)), f(9, f(3, nil, nil), f(7, nil, nil))), []int{3, 2, 4, 8})
}

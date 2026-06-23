package lc0210

import "slices"

func findOrder(numCourses int, prerequisites [][]int) []int {
	children := map[int][]int{}
	parents := map[int][]int{}
	for _, p := range prerequisites {
		children[p[1]] = append(children[p[1]], p[0])
		parents[p[0]] = append(parents[p[0]], p[1])
	}

	q := []int{}
	for i := 0; i < numCourses; i++ {
		if parents[i] == nil {
			q = append(q, i)
		}
	}

	out := []int{}

	for len(q) != 0 {
		window := q
		for _, course := range window {
			out = append(out, course)
			q = append(q, children[course]...)
		}
		q = q[len(window):]
	}

	out2 := []int{}
	seen := map[int]bool{}
	for _, course := range slices.Backward(out) {
		if !seen[course] {
			out2 = append(out2, course)
			seen[course] = true
		}
	}

	slices.Reverse(out2)
	return out2
}

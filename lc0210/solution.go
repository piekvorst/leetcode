package lc0210

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

	seen := map[int]bool{}
	out := []int{}

	for len(q) != 0 {
		window := q
		for _, course := range window {
			if !seen[course] {
				out = append(out, course)
				q = append(q, children[course]...)
				seen[course] = true
			}
		}
		q = q[len(window):]
	}

	return out
}

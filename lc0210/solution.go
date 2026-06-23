package lc0210

func findOrder(ncourses int, prerequisites [][]int) []int {
	children := map[int][]int{}
	parents := map[int][]int{}
	for _, p := range prerequisites {
		children[p[1]] = append(children[p[1]], p[0])
		parents[p[0]] = append(parents[p[0]], p[1])
	}

	roots := []int{}
	for i := 0; i < ncourses; i++ {
		if parents[i] == nil {
			roots = append(roots, i)
		}
	}

	weights := map[int]int{}

	weight := 1
	q := append([]int(nil), roots...)
	for len(q) != 0 {
		window := q
		for _, course := range window {
			if weight > weights[course] {
				q = append(q, children[course]...)
				weights[course] = weight
			}
		}

		q = q[len(window):]
		weight++

		if weight > ncourses+1 {
			return nil
		}
	}

	for course := 0; course < ncourses; course++ {
		if (children[course] != nil || parents[course] != nil) && weights[course] == 0 {
			return nil
		}
	}

	out := []int{}

	weight = 1
	q = append([]int(nil), roots...)
	for len(q) != 0 {
		window := q
		for _, course := range window {
			if weight == weights[course] {
				q = append(q, children[course]...)
				out = append(out, course)
				weights[course] = 0
			}
		}

		q = q[len(window):]
		weight++
	}

	return out
}

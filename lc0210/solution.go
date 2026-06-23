package lc0210

func findOrder(ncourses int, prerequisites [][]int) []int {
	children := make(map[int][]int, ncourses)
	parents := make(map[int][]int, ncourses)
	for _, p := range prerequisites {
		if children[p[1]] == nil {
			children[p[1]] = make([]int, 0, ncourses)
		}
		if parents[p[0]] == nil {
			parents[p[0]] = make([]int, 0, ncourses)
		}

		children[p[1]] = append(children[p[1]], p[0])
		parents[p[0]] = append(parents[p[0]], p[1])
	}

	roots := make([]int, 0, ncourses)
	for i := 0; i < ncourses; i++ {
		if parents[i] == nil {
			roots = append(roots, i)
		}
	}

	weights := make(map[int]int, ncourses)

	q := make([]int, len(roots))
	copy(q, roots)
	weight := 1

	for len(q) != 0 {
		window := q
		for _, course := range window {
			if weight > weights[course] {
				q = append(q, children[course]...)
				weights[course] = weight
			}
		}

		nextwin := q[len(window):]
		copy(q, nextwin)
		q = q[:len(nextwin)]

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

	out := make([]int, 0, ncourses)

	weight = 1
	q = make([]int, len(roots))
	copy(q, roots)

	for len(q) != 0 {
		window := q
		for _, course := range window {
			if weight == weights[course] {
				q = append(q, children[course]...)
				out = append(out, course)
				weights[course] = 0
			}
		}

		nextwin := q[len(window):]
		copy(q, nextwin)
		q = q[:len(nextwin)]
		weight++
	}

	return out
}

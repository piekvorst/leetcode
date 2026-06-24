package lc0022

func generateParenthesis(n int) []string {
	if n == 1 {
		return []string{"()"}
	}

	var out []string

	for _, prev := range generateParenthesis(n - 1) {
		out = append(out, "("+prev+")")
	}

	for _, perm := range permutations(n) {
		s := ""
		for _, addend := range perm {
			if addend == n {
				break
			}

			for i := 0; i < addend; i++ {
				s += "("
			}
			for i := 0; i < addend; i++ {
				s += ")"
			}
		}
		if s != "" {
			out = append(out, s)
		}
	}

	return out
}

// permutations evaluates all the ways one can sum [1; n] to get
// n.
func permutations(n int) [][]int {
	var out [][]int

	var dfs func(int, []int, int)
	dfs = func(addend int, trace []int, tracesum int) {
		trace = append(trace, addend)
		tracesum += addend

		if tracesum == n {
			out = append(out, append([]int(nil), trace...))
			return
		}
		if tracesum > n {
			return
		}

		for j := 1; j <= n; j++ {
			dfs(j, trace, tracesum)
		}
	}

	buf := make([]int, 0, n)
	for addend := 1; addend <= n; addend++ {
		dfs(addend, buf, 0)
	}

	return out
}

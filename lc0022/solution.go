package lc0022

func generateParenthesis(n int) []string {
	var out []string

	s := make([]byte, 0, 2*n)

	var dfs func([]byte, int)
	dfs = func(s []byte, nopen int) {
		if len(s) == 2*n {
			if nopen == 0 {
				out = append(out, string(s))
			}
			return
		}
		if nopen == 0 {
			dfs(append(s, '('), 1)
		} else {
			dfs(append(s, '('), nopen+1)
			dfs(append(s, ')'), nopen-1)
		}
	}
	dfs(s, 0)

	return out
}

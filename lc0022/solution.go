package lc0022

func generateParenthesis(n int) []string {
	var out []string

	var dfs func(string, int)
	dfs = func(s string, nopen int) {
		if len(s) == 2*n {
			if nopen == 0 {
				out = append(out, s)
			}
			return
		}
		if nopen == 0 {
			dfs(s+"(", 1)
		} else {
			dfs(s+"(", nopen+1)
			dfs(s+")", nopen-1)
		}
	}
	dfs("", 0)

	return out
}

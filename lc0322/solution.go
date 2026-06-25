package lc0322

func coinChange(coins []int, amount int) int {
	var out *int

	var dfs func(int, int)
	dfs = func(sum, ncoins int) {
		if sum > amount {
			return
		}
		if sum == amount {
			if out == nil {
				out = (func(n int) *int { return &n })(ncoins)
			} else {
				*out = min(*out, ncoins)
			}
		}

		for _, c := range coins {
			dfs(sum+c, ncoins+1)
		}
	}

	dfs(0, 0)

	if out != nil {
		return *out
	} else {
		return -1
	}
}

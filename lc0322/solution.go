package lc0322

var mem = make([]int, 10_001)

func coinChange(coins []int, amount int) int {
	mem = mem[:amount+1]
	clear(mem)

	var out *int

	var dfs func(int, int)
	dfs = func(sum, ncoins int) {
		if sum > amount {
			return
		}
		if mem[sum] != 0 && mem[sum] < ncoins {
			return
		}
		if sum == amount {
			if out == nil {
				out = (func(n int) *int { return &n })(ncoins)
			} else {
				*out = min(*out, ncoins)
			}
		}

		if mem[sum] == 0 {
			mem[sum] = ncoins
		} else {
			mem[sum] = min(mem[sum], ncoins)
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

func abs(n int) int {
	if n < 0 {
		return -n
	} else {
		return n
	}
}

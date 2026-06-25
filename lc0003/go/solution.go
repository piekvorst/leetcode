package lc0003

func lengthOfLongestSubstring(s string) int {
	var out int

	var seen [128]bool

	var left, right int
	for right < len(s) {
		for seen[s[right]] && left < right {
			seen[s[left]] = false
			left++
		}
		for right < len(s) && !seen[s[right]] {
			seen[s[right]] = true
			right++
		}
		out = max(out, right-left)
	}

	return out
}

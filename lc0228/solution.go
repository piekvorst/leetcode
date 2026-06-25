package lc0228

import "fmt"

func summaryRanges(nums []int) []string {
	var out []string

	left, right := 0, 0
	for right < len(nums) {
		left = right
		for right < len(nums) {
			if right > left && nums[right]-nums[right-1] != 1 {
				break
			}
			right++
		}

		if left != right-1 {
			out = append(out, fmt.Sprintf("%v->%v", nums[left], nums[right-1]))
		} else {
			out = append(out, fmt.Sprint(nums[left]))
		}
	}

	return out
}

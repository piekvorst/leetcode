package lc0033

import "sort"

func search(nums []int, target int) int {
	k := sort.Search(
		len(nums),
		func(i int) bool {
			return i > 0 && nums[0] > nums[i]
		},
	)

	l := sort.Search(
		k,
		func(i int) bool {
			return nums[i] >= target
		},
	)

	m := sort.Search(
		len(nums[k:]),
		func(i int) bool {
			return nums[k:][i] >= target
		},
	)

	if l < len(nums) && nums[l] == target {
		return l
	} else if m < len(nums[k:]) && nums[k:][m] == target {
		return k + m
	} else {
		return -1
	}
}

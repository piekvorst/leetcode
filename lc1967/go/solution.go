package lc1967

import "strings"

func numOfStrings(patterns []string, word string) int {
	var out int

	for _, p := range patterns {
		if strings.Contains(word, p) {
			out++
		}
	}

	return out
}

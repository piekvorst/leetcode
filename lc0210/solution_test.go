package lc0210

import (
	"slices"
	"testing"
)

func TestFindOrder(t *testing.T) {
	f := func(t *testing.T, name string, numCourses int, prerequisites [][]int, want [][]int) {
		t.Helper()

		t.Run(name, func(t *testing.T) {
			t.Helper()

			got := findOrder(numCourses, prerequisites)
			for _, w := range want {
				if slices.Equal(got, w) {
					return
				}
			}

			t.Errorf("unexpected: %v", got)
		})
	}

	f(t, "example1", 2, [][]int{{1, 0}}, [][]int{{0, 1}})

	// 0 -----> 1 ----> 3
	//   \          __^
	//    \__> 2 __/
	//
	f(t, "example2", 4, [][]int{{1, 0}, {2, 0}, {3, 1}, {3, 2}}, [][]int{{0, 2, 1, 3}, {0, 1, 2, 3}})

	f(t, "example3", 1, [][]int{}, [][]int{{0}})

	// 3 -> 2 -> 1 ------------------> 0
	//             \               __^
	//              \__> 5 -> 4 __/
	//
	f(t, "wronganswer1", 6, [][]int{{2, 3}, {1, 2}, {0, 1}, {0, 4}, {4, 5}, {5, 1}}, [][]int{{3, 2, 1, 5, 4, 0}})

	// 2 -> 1 -------> 0
	//        ^__    /
	//           \__/
	//
	f(t, "tle1", 3, [][]int{{1, 0}, {1, 2}, {0, 1}}, [][]int{{}})

	// 6 -> 5 -------------> 2 -------------> 0 -> 1
	//        \          __^   \          __^
	//         \__> 4 __/       \__> 3 __/
	//
	f(
		t,
		"wronganswer2",
		7,
		[][]int{{1, 0}, {0, 3}, {0, 2}, {3, 2}, {2, 5}, {4, 5}, {5, 6}, {2, 4}},
		[][]int{{6, 5, 4, 2, 3, 0, 1}},
	)
}

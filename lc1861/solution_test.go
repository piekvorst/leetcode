package lc1861

import (
	"fmt"
	"reflect"
	"testing"
)

type boxstringer [][]byte

func TestRotateTheBox(t *testing.T) {
	f := func(t *testing.T, name string, box, want [][]byte) {
		t.Helper()

		t.Run(name, func(t *testing.T) {
			t.Helper()

			if got := rotateTheBox(box); !reflect.DeepEqual(got, want) {
				t.Errorf("RotatteTheBox returned wrong answer: %v", boxstringer(got))
			}
		})
	}

	f(t, "example1", [][]byte{{'#', '.', '#'}}, [][]byte{{'.'}, {'#'}, {'#'}})

	f(
		t,
		"example2",
		[][]byte{
			{'#', '.', '*', '.'},
			{'#', '#', '*', '.'},
		},
		[][]byte{
			{'#', '.'},
			{'#', '#'},
			{'*', '*'},
			{'.', '.'},
		},
	)

	f(
		t,
		"example3",
		[][]byte{
			{'#', '#', '*', '.', '*', '.'},
			{'#', '#', '#', '*', '.', '.'},
			{'#', '#', '#', '.', '#', '.'},
		},
		[][]byte{
			{'.', '#', '#'},
			{'.', '#', '#'},
			{'#', '#', '*'},
			{'#', '*', '.'},
			{'#', '.', '*'},
			{'#', '.', '.'},
		},
	)
}

func (b boxstringer) String() string {
	s := ""

	for row := range b {
		for col := range b[row] {
			s += fmt.Sprintf("%c ", b[row][col])
		}

		s += "| "
	}

	return s
}

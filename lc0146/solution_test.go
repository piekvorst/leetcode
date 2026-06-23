package lc0146

import "testing"

func TestLRUCache(t *testing.T) {
	t.Run("example1", func(t *testing.T) {
		lru := Constructor(2)
		lru.Put(1, 1)
		lru.Put(2, 2)
		if got := lru.Get(1); got != 1 {
			t.Fatalf("unexpected: %v", got)
		}
		lru.Put(3, 3)
		if got := lru.Get(2); got != -1 {
			t.Fatalf("unexpected: %v", got)
		}
		lru.Put(4, 4)
		if got := lru.Get(1); got != -1 {
			t.Fatalf("unexpected: %v", got)
		}
		if got := lru.Get(3); got != 3 {
			t.Fatalf("unexpected: %v", got)
		}
		if got := lru.Get(4); got != 4 {
			t.Fatalf("unexpected: %v", got)
		}
	})

	t.Run("wronganswer1", func(t *testing.T) {
		lru := Constructor(2)
		lru.Put(1, 0)
		lru.Put(2, 2)
		if got := lru.Get(1); got != 0 {
			t.Fatalf("unexpected: %v", got)
		}
		lru.Put(3, 3)
		if got := lru.Get(2); got != -1 {
			t.Fatalf("unexpected: %v", got)
		}
		lru.Put(4, 4)
		if got := lru.Get(1); got != -1 {
			t.Fatalf("unexpected: %v", got)
		}
		if got := lru.Get(3); got != 3 {
			t.Fatalf("unexpected: %v", got)
		}
		if got := lru.Get(4); got != 4 {
			t.Fatalf("unexpected: %v", got)
		}
	})

	t.Run("wronganswer2", func(t *testing.T) {
		lru := Constructor(1)
		lru.Put(2, 1)
		if got := lru.Get(2); got != 1 {
			t.Fatalf("unexpected: %v", got)
		}
		lru.Put(3, 2)
		if got := lru.Get(2); got != -1 {
			t.Fatalf("unexpected: %v", got)
		}
		if got := lru.Get(3); got != 2 {
			t.Fatalf("unexpected: %v", got)
		}
	})
}

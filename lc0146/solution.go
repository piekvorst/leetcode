package lc0146

import "fmt"

type LRUCache struct {
	Cap  int
	Dict map[int]*node

	Head, Tail *node
}

type node struct {
	K, V       int
	Prev, Next *node
}

func Constructor(capacity int) LRUCache {
	return LRUCache{
		Cap:  capacity,
		Dict: make(map[int]*node, capacity),
	}
}

func (lru *LRUCache) Get(key int) int {
	n, found := lru.Dict[key]
	if !found {
		return -1
	}

	// if the found node is a tail and it's not a single-node list, remove it
	//
	if n == lru.Tail && lru.Tail.Prev != nil {
		lru.Tail.Next = nil
		lru.Tail = lru.Tail.Prev
	}

	// remove the node from its neighbors
	//
	if n.Prev != nil {
		n.Prev.Next = n.Next
	}
	if n.Next != nil {
		n.Next.Prev = n.Prev
	}

	// make the node a new head
	//
	n.Prev = nil
	n.Next = lru.Head

	// adjust the old head
	//
	lru.Head.Prev = n
	lru.Head = n

	return n.V
}

func (lru *LRUCache) Put(key int, value int) {
	if n, found := lru.Dict[key]; found {
		n.V = value

		// adjust the updated node's position
		//
		lru.Get(value)

		return
	}

	// create a new node
	//
	lru.Dict[key] = &node{
		K: key,
		V: value,
	}

	// adjust the tail
	//
	if lru.Tail == nil {
		lru.Tail = lru.Dict[key]
	}

	// adjust the old head
	//
	if lru.Head == nil {
		lru.Head = lru.Dict[key]
	} else {

		// make the new node a new head
		//
		lru.Dict[key].Next = lru.Head
		lru.Head.Prev = lru.Dict[key]
		lru.Head = lru.Dict[key]
	}

	if len(lru.Dict) > lru.Cap {
		delete(lru.Dict, lru.Tail.K)

		// make new tail
		//
		if lru.Tail.Prev != nil {
			lru.Tail.Prev.Next = nil
		}

		// adjust the old tail
		//
		lru.Tail = lru.Tail.Prev
	}
}

func printlist(head *node) {
	fmt.Printf("nil <-> ")
	for n := head; n != nil; n = n.Next {
		fmt.Printf("(%v:%v) <-> ", n.K, n.V)
	}
	fmt.Printf("nil\n")
}

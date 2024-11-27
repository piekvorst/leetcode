#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	int val;
	struct node **children;
	int nchildren;
};
typedef struct node Node;

Node *globalqueue[1000];

Node *
mknode(int val)
{
	Node *n;
	n = calloc(1, sizeof(*n));
	n->val = val;
	n->children = calloc(500, sizeof(n->children[0]));
	return n;
}

int
bfs(Node **graph, int cities)
{
	bool seen[501] = {0};

	Node **queue = globalqueue;
	int nqueue = 0;

	queue[nqueue++] = graph[0];

	int depth = 0;

	while (nqueue > 0) {
		int prevlen = nqueue;

		for (Node **qp = queue; qp != queue+prevlen; ++qp) {
			if ((*qp)->val == cities-1)
				return depth;

			seen[(*qp)->val] = true;

			for (Node **child = (*qp)->children; child != (*qp)->children+(*qp)->nchildren; ++child) {
				if (!seen[(*child)->val])
					queue[nqueue++] = *child;
			}
		}

		memmove(queue, queue+prevlen, (nqueue-prevlen)*sizeof(queue[0]));
		nqueue -= prevlen;

		++depth;
	}

	return depth;
}

int *
shortestDistanceAfterQueries
	(int cities, int **queries, int nqueries, int *mqueries, int *ndistances)
{
	Node *graph[501] = {0};

	for (int i = 0; i < cities; ++i)
		graph[i] = mknode(i);

	for (int i = 1; i < cities; ++i) {
		Node *parent = graph[i-1], *child = graph[i];
		parent->children[parent->nchildren++] = child;
	}

	int *distances;
	distances = calloc(nqueries, sizeof(*distances));

	int *dp = distances;

	for (int **qp = queries; qp != queries+nqueries; ++qp) {
		Node *parent = graph[(*qp)[0]], *child = graph[(*qp)[1]];
		parent->children[parent->nchildren++] = child;

		*(dp++) = bfs(graph, cities);
	}

	*ndistances = nqueries;
	return distances;
}

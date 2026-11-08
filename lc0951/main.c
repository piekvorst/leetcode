#include <stdbool.h>
#include <stdio.h>

#define NODE(v, l, r) (&(struct TreeNode){.val = (v), .left = (l), .right = (r)})
#define LEAF(v) (&(struct TreeNode){.val = (v)})

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

bool
flipEquiv(struct TreeNode *h1, struct TreeNode *h2);

void
example1(void)
{
	printf("main.c:/example1/\n");

	bool equiv = flipEquiv(
		NODE(
			1,
			NODE(
				2,
				LEAF(4),
				NODE(5, LEAF(7), LEAF(8))
			),
			NODE(3, LEAF(6), NULL)
		),
		NODE(
			1,
			NODE(3, NULL, LEAF(6)),
			NODE(
				2,
				LEAF(4),
				NODE(5, LEAF(8), LEAF(7))
			)
		)
	); // true

	printf("equiv: %d\n", equiv);
	printf("\n");
}

void
example2(void)
{
	printf("main.c:/example2/\n");

	bool equiv = flipEquiv(NULL, NULL); // true

	printf("equiv: %d\n", equiv);
	printf("\n");
}

void
example3(void)
{
	printf("main.c:/example3/\n");

	bool equiv = flipEquiv(NULL, LEAF(1)); // false

	printf("equiv: %d\n", equiv);
	printf("\n");
}

int
main(void)
{
	example1();
	example2();
	example3();

	return 0;
}

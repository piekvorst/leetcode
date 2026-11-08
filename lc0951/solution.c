#include <stdbool.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

bool
flipEquiv(struct TreeNode *h1, struct TreeNode *h2)
{
	if (h1 && !h2 || !h1 && h2)
		return false;

	if (!h1 && !h2)
		return true;

	if (h1->val != h2->val)
		return false;

	if (!flipEquiv(h1->left, h2->right) && !flipEquiv(h1->left, h2->left))
		return false;

	if (!flipEquiv(h1->right, h2->left) && !flipEquiv(h1->right, h2->right))
		return false;

	return true;
}

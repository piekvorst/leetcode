#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX(x, y) ((x)>(y) ? (x) : (y))

typedef struct rtnode Rtnode;
struct rtnode
{
	char *s;
	int count;
	Rtnode *children[2];
};

Rtnode *
rtnew(char *s, int count)
{
	Rtnode *n;
	n = calloc(1, sizeof(*n));
	n->s = strdup(s);
	n->count = count;
	return n;
}

void
rtins(Rtnode **headp, char *s)
{
	// On each iteration head represents s[0].
	// That is, head->s[0] == s[0].

	if (!*headp) {
		*headp = rtnew(s, 1);
		return;
	}

	Rtnode *head = *headp;

	if (0 == strcmp(head->s, s)) {
		head->count++;
		return;
	}

	// Find first i such that head->s[i] != s[i].
	//
	size_t i = 0;
	while (head->s[i] && s[i] && head->s[i] == s[i])
		++i;

	// head->s is fully a prefix of s.
	//
	if (!head->s[i]) {
		rtins(&head->children[s[i]-'0'], s + i);
		return;
	}

	// Keep matching part, make the rest its child.
	//
	Rtnode *subtree = rtnew(head->s + i, head->count);
	head->count = 0;
	for (int i = 0; i < 2; ++i) {
		subtree->children[i] = head->children[i];
		head->children[i] = NULL;
	}
	head->children[head->s[i] - '0'] = subtree;

	if (!s[i]) {
		// s is fully a prefix of head->s.

		head->count = 1;
	} else {
		// s is partly a prefix of head->s.

		head->count = 0;
		head->children[s[i] - '0'] = rtnew(s + i, 1);
	}

	// Only keep matching part of the string.
	//
	head->s[i] = 0;
}

bool
rtcontains(Rtnode *head, char *s)
{
	// On each iteration head represents s[0].
	// That is, head->s[0] == s[0].

	if (!head)
		return false;

	if (0 == strcmp(head->s, s))
		return head->count > 0;

	// Find first i such that head->s[i] != s[i].
	//
	size_t i = 0;
	while (head->s[i] && s[i] && head->s[i] == s[i])
		++i;

	// head->s is fully a prefix of s.
	//
	if (!head->s[i])
		return rtcontains(head->children[s[i] - '0'], s+i);

	// s is either fully (!s[i]) or partly a prefix of head->s.
	//
	return false;
}

int
rtmaxcount(Rtnode *head)
{
	if (!head)
		return 0;

	int count = head->count;
	for (int i = 0; i < 2; ++i) {
		int x = rtmaxcount(head->children[i]);
		count = MAX(count, x);
	}

	return count;
}

void
strrev(char *dst, char *src)
{
	char *dstp = dst;

	for (char *srcp = src; *srcp; ++srcp) {
		if (*srcp == '0') *(dstp++) = '1';
		else if (*srcp == '1') *(dstp++) = '0';
		else abort();
	}

	*dstp = 0;
}

int
maxEqualRowsAfterFlips(int **matrix, int rows, int *cols)
{
	Rtnode *root = rtnew("/", 0);

	for (int **p = matrix; p != matrix+rows; ++p) {
		char s[301] = {0};
		char *sp = s;

		for (int *q = *p; q != *p+cols[0]; ++q)
			*(sp++) = *q + '0';

		*sp = 0;

		char rev[301] = {0};
		strrev(rev, s);

		if (rtcontains(root->children[*rev-'0'], rev))
			rtins(&root->children[*rev-'0'], rev);
		else
			rtins(&root->children[*s-'0'], s);
	}

	return rtmaxcount(root);
}

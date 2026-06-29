#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct rtnode Rtnode;
struct rtnode
{
	char *s;
	int count;
	Rtnode *children[128];
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
		rtins(&head->children[s[i]], s + i);
		return;
	}

	// Keep matching part, make the rest its child.
	//
	Rtnode *subtree = rtnew(head->s + i, head->count);
	head->count = 0;
	for (int i = 0; i < 128; ++i) {
		subtree->children[i] = head->children[i];
		head->children[i] = NULL;
	}
	head->children[head->s[i]] = subtree;

	if (!s[i]) {
		// s is fully a prefix of head->s.

		head->count = 1;
	} else {
		// s is partly a prefix of head->s.

		head->count = 0;
		head->children[s[i]] = rtnew(s + i, 1);
	}

	// Only keep matching part of the string.
	//
	head->s[i] = 0;
}

bool
rtprefix(Rtnode *head, char *s)
{
	// On each iteration head represents s[0].
	// That is, head->s[0] == s[0].

	if (!head)
		return false;

	if (0 == strcmp(head->s, s))
		return true;

	// Find first i such that head->s[i] != s[i].
	//
	size_t i = 0;
	while (head->s[i] && s[i] && head->s[i] == s[i])
		++i;

	// head->s is fully a prefix of s.
	//
	if (!head->s[i])
		return rtprefix(head->children[s[i]], s+i);

	return !s[i];
}

void
rtdbg(struct rtnode *head, int shift)
{
        if (!head)
                return;
        printf("%*s/", shift, "");
        if (head->s[0] != '/')
                printf("%s", head->s);
        if (head->count > 0)
                printf(".");
        printf("\n");
        for (int i = 0; i < 128; i++)
                rtdbg(head->children[i], shift + 4);
}

int
numOfStrings(char **patterns, int npatterns, char *word)
{
	int out = 0;

	Rtnode *root = rtnew("/", 0);

	for (char *wp = word; *wp; ++wp)
		rtins(&root->children[*wp], wp);

	for (char **p = patterns; p != patterns+npatterns; ++p) {
		if (rtprefix(root->children[**p], *p))
			++out;
	}

	return out;
}

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct rtnode Rtnode;
struct rtnode
{
	char *s;
	int last;
	Rtnode *children[256];
};

Rtnode *
rtnew(char *s, int last)
{
	Rtnode *n;
	n = calloc(1, sizeof(*n));
	n->s = strdup(s);
	n->last = last;
	return n;
}

void
rtins(Rtnode **headp, char *s)
{
	// On each iteration head represents s[0].
	// That is, head->s[0] == s[0].

	if (!*headp) {
		*headp = rtnew(s, true);
		return;
	}

	Rtnode *head = *headp;

	if (0 == strcmp(head->s, s)) {
		head->last++;
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
	Rtnode *subtree = rtnew(head->s + i, head->last);
	for (int i = 0; i < 256; ++i) {
		subtree->children[i] = head->children[i];
		head->children[i] = NULL;
	}
	head->children[head->s[i]] = subtree;

	if (!s[i]) {
		// s is fully a prefix of head->s.

		head->last = 1;
	} else {
		// s is partly a prefix of head->s.

		head->last = 0;
		head->children[s[i]] = rtnew(s + i, 1);
	}

	// Only keep matching part of the string.
	//
	head->s[i] = 0;
}

int
rtsum(Rtnode *head)
{
	if (!head)
		return 0;

	int n = 0;

	for (int i = 0; i < 256; ++i)
		n += rtsum(head->children[i]);

	return head->last + n;
}

int
rtcontains(Rtnode *head, char *s)
{
	// On each iteration head represents s[0].
	// That is, head->s[0] == s[0].

	if (!head)
		return 0;

	if (0 == strcmp(head->s, s))
		return rtsum(head);

	// Find first i such that head->s[i] != s[i].
	//
	size_t i = 0;
	while (head->s[i] && s[i] && head->s[i] == s[i])
		++i;

	// head->s is fully a prefix of s.
	//
	if (!head->s[i])
		return rtcontains(head->children[s[i]], s+i);

	// s is fully a prefix of head->s.
	if (!s[i])
		return rtsum(head);

	// s is partly a prefix of head->s.
	//
	return 0;
}

void
rtnuke(Rtnode *head)
{
	if (!head)
		return;
	for (int i = 0; i < 256; ++i)
		rtnuke(head->children[i]);
	free(head->s);
	free(head);
}

void
rtprint(Rtnode *head, int shift)
{
	if (!head)
		return;

	printf("%*s%s", 4*shift, "", head->s);
	if (head->last)
		printf(". x%d", head->last);
	printf("\n");

	for (int i = 0; i < 256; ++i)
		rtprint(head->children[i], shift + 1);
}

int
prefixCount(char **words, int nwords, const char *pref)
{
	int n = 0;

	for (char **w = words; w != words+nwords; ++w) {
		const char *pp = pref;
		const char *wp = *w;

		while (*pp && *wp && *pp == *wp) {
			++pp;
			++wp;
		}

		if (!*pp)
			++n;
	}

	return n;
}

#include <stdbool.h>
#include <string.h>

bool
prefix(char *s, char *p)
{
	return strncmp(s, p, strlen(p)) == 0;
}

int
prefixCount(char **words, int nwords, char *pref)
{
	int n = 0;

	for (char **w = words; w != words+nwords; ++w) {
		if (prefix(*w, pref))
			++n;
	}

	return n;
}

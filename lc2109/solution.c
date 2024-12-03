#include <stdlib.h>
#include <string.h>

char *
addSpaces(char *s, int *spaces, int nspaces)
{
	size_t len = strlen(s);
	int *spacesp = spaces + nspaces - 1;

	char *sp = s + len - 1;

	char *withspaces;
	withspaces = calloc(len + nspaces + 1, sizeof(*withspaces));

	char *wp = withspaces + len + nspaces;
	*(wp--) = 0;

	while (sp != s-1) {
		*(wp--) = *(sp--);
		if (spacesp >= spaces && sp+1-s == *spacesp) {
			*(wp--) = ' ';
			--spacesp;
		}
	}

	return withspaces;
}

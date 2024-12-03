#include <stdlib.h>
#include <string.h>

char *
addSpaces(char *s, int *spaces, int nspaces)
{
	size_t len = strlen(s);
	int *spacesp = spaces + nspaces - 1;

	char *sp = s + len - 1;

	char *buf;
	buf = calloc(len + nspaces + 1, sizeof(*buf));

	char *bufp = buf + len + nspaces;
	*(bufp--) = 0;

	while (sp != s-1) {
		if (spacesp >= spaces && sp-s == *spacesp) {
			*(bufp--) = *(sp--);
			*(bufp--) = ' ';
			--spacesp;
		} else {
			*(bufp--) = *(sp--);
		}
	}

	return buf;
}

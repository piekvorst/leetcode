#include <string.h>

// 3e5 string + 3e5 spaces + 0
char buf[600001];

char *
addSpaces(char *s, int *spaces, int nspaces)
{
	size_t len = strlen(s);
	int *spacesp = spaces + nspaces - 1;

	char *sp = s + len - 1;
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

	return strdup(buf);
}

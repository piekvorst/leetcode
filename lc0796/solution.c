#include <stdbool.h>
#include <string.h>

char buf[201];

bool
rotateString(char *s, char *goal)
{
	strcpy(buf, s);

	char *bufp = buf, *bufq = buf + strlen(s);

	for (char *sp = s; *sp; ++sp) {
		if (strcmp(goal, bufp) == 0)
			return true;

		*(bufq++) = *(bufp++);
		*bufq = 0;
	}

	return false;
}

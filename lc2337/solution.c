#include <stdbool.h>

bool
canChange(char *start, char *target)
{
	char *sp = start, *tp = target;

	for (; *sp; ++sp) {
		if (*sp == '_')
			continue;

		while (*tp && *tp == '_')
			++tp;

		if (!*tp || *tp != *sp)
			return false;

		++tp;
	}

	return true;
}

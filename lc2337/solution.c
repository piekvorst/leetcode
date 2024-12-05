#include <stdbool.h>

/*
	L in start cannot be matched by an L in target that stays to
	the right.
*/

bool
canChange(char *start, char *target)
{
	char *sp = start, *tp = target;

	for (; *sp; ++sp) {
		if (*sp == '_')
			continue;

		while (*tp && *tp == '_')
			++tp;

		if (!*tp)
			return false;

		if (*sp == 'L' && *tp == 'L' && sp-start < tp-target)
			return false;

		if (*sp == 'R' && *tp == 'R' && sp-start > tp-target)
			return false;

		if (*sp != *tp)
			return false;

		++tp;
	}

	return true;
}

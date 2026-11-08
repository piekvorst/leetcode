#include <stdbool.h>

bool
isCircularSentence(char *sentence)
{
	char *sp;
	for (sp = sentence; *sp; ++sp) {
		if (*sp == ' ' && sp[-1] != sp[1])
			return false;
	}

	return sp[-1] == sentence[0];
}

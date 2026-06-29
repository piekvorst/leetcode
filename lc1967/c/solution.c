#include <string.h>

int
numOfStrings(char **patterns, int npatterns, char* word)
{
	int out = 0;

	for (char **p = patterns; p != patterns+npatterns; ++p) {
		if (strstr(word, *p))
			++out;
	}

	return out;
}

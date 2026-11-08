#include <stdlib.h>
#include <string.h>

int
cmpstr(const void *a, const void *b)
{
	const char *arg1 = *(const char **)a;
	const char *arg2 = *(const char **)b;

	return strcmp(arg1, arg2);
}

char **
removeSubfolders(char **folder, int nfolder, int *nout)
{
	char **p, **q;

	char **out;
	out = calloc(nfolder, sizeof(*out));
	p = out;
	for (q = folder; q != folder+nfolder;)
		*(p++) = *(q++);

	qsort(out, nfolder, sizeof(*out), cmpstr);

	p = out;
	for (char **sub = out+1; sub != out+nfolder; ++sub) {
		int m = strlen(*p);
		int n = strlen(*sub);

		if (m < n && strncmp(*p, *sub, m) == 0 && (*sub)[m] == '/')
			*sub = NULL;
		else
			p = sub;
	}

	p = out;
	for (q = out; q != out+nfolder; ++q) {
		if (*q)
			*(p++) = strdup(*q);
	}

	*nout = p - out;
	return out;
}

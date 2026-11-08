#include <stdlib.h>
#include <string.h>

int *
decrypt(int *code, int len, int k, int *nout)
{
	int *prefix = code;
	prefix = calloc(len, sizeof(*prefix));

	memcpy(prefix, code, len * sizeof(*code));

	/* build the prefix */
	int *prev = prefix, *pp = prefix + 1;
	while (pp != prefix+len)
		*(pp++) += *(prev++);

	int *decrypted;
	decrypted = calloc(len, sizeof(*decrypted));

	int *dp = decrypted;

	for (int i = 0; i < len; ++i) {
		if (k > 0 && i+k < len)
			*(dp++) = prefix[i+k] - prefix[i];
		else if (k > 0 && i+k >= len)
			*(dp++) = prefix[len-1]-prefix[i] + prefix[i+k-len];
		else if (k < 0 && i-(-k)-1 >= 0)
			*(dp++) = prefix[i-1] - prefix[i-(-k)-1];
		else if (k < 0 && i-(-k) <= 0)
			*(dp++) = prefix[i]-code[i] + prefix[len-1]-prefix[len-1-(-k-i)];
	}

	free(prefix);

	*nout = len;
	return decrypted;
}

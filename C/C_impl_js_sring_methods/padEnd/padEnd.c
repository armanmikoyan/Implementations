#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *padEnd(char *str, const char *pad, int length_pad)
{
	char *result = malloc(strlen(str) + length_pad);
	strcpy(result, str);
	char *tmp = result;
	while (*tmp)
	{
		tmp++;
	}

	for (int i = 0; i < length_pad; ++i)
	{
		tmp[i] = *pad;
	}

	return result;
}

int main()
{
	char *ch = "Arman";
	const char *pad = "!";
	const int length_pad = 5;
	char *res = padEnd(ch, pad, length_pad);
	printf("%s\n", res);
	return 0;
}

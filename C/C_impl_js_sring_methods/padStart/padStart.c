#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *padStart(char *str, const char *pad, int length_pad)
{
	char *result = malloc(strlen(str) + length_pad);
        
	for (int i = 0; i < length_pad; ++i)
	{
		result[i] = *pad;
	}
	char *tmp = result;
	while (*tmp)
	{
		tmp++;
	}
	
	strcpy(tmp, str);

	return result;
}

int main()
{
	char *ch = "Arman";
	const char *pad = "!";
	const int length_pad = 5;
	char *res = padStart(ch, pad, length_pad);
	printf("%s\n", res);
	return 0;
}

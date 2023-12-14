#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *repeat(char *str, const char *pad, int rep,int pad_len)
{
	char *result = malloc(strlen(str) + rep * pad_len);
	strcpy(result, str);
	char *tmp = result;
	while (*tmp)
	{
		tmp++;
	}

	for (int i = 0; i < rep; ++i)
	{
	  for(int i = 0; i < pad_len; ++i){
		tmp[i] = pad[i];
	 }
    tmp +=pad_len;
	}

	return result;
}

int main()
{
	char *ch = "Hello";
	const char *pad = " world";
	const int rep = 5;
        const int pad_len = strlen(pad);
	char *res = repeat(ch, pad, rep,pad_len);
	printf("%s\n", res);
	return 0;
}

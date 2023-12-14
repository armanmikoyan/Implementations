#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *trimEnd(char str[])
{
	char *tmp = malloc(strlen(str));
	strcpy(tmp, str);
	int length = strlen(str);
	for (int i = 0; i < length; ++i)
	{
		if (str[i] == ' ')
		{
			tmp++;
		}
		else
		{
			return tmp;
		}
	}

	return tmp;
}

int main()
{
	char str[] = "    Arman m  ";
	printf("%s length-> %lu\n", str, strlen(str));
	char *res = trimEnd(str);
	printf("%s length-> %lu\n", res, strlen(res));

	return 0;

}

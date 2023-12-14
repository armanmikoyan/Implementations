#include <stdio.h>
#include <string.h>


void trimEnd(char str[])
{
	int len = strlen(str) - 1;
	for (int i = len; i >= 0; --i)
	{
		if (str[i] == ' ')
		{
			str[i] = '\0';
		}
		else
		{
			return;
		}
	}
}

int main()
{
	char str[] = "Arman m  ";
	printf("%s length-> %lu\n", str, strlen(str));
	trimEnd(str);
	printf("%s length-> %lu\n", str, strlen(str));

	return 0;
}

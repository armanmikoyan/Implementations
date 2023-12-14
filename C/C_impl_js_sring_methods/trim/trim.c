#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *trim(char str[], int len)
{
	char *ptr = str;
	char *tmp = ptr;
	while (*tmp == ' ')
	{
		tmp++;
	}

	for (int i = len; i >= 0; --i)
	{
		if (ptr[i] == ' ')
		{
			ptr[i] = '\0';
		}
		else
		{
			ptr = tmp;
			return ptr;
		}
	}

	return ptr;
}

int main()
{
	char str[] = "    Arman m        ";
	int len = strlen(str) - 1;
	printf("%s%c\n", str, 'a');
	char *res = trim(str, len);
	printf("%s%c\n", res, 'a');

	return 0;

}

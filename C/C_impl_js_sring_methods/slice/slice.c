#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

char *slice( char *str, const int index, const int end)
{
	char *tmp;
	if (end == 0)
	{
		tmp = str + index;
	}
	else if (end > 0 && end > index)
	{
		tmp = malloc(end - index);
		strcpy(tmp, str);
		tmp[end + 1] = '\0';
		tmp = tmp + index;
	}

	return tmp;
}

int main()
{
         char *str = "hello world morld ";
	const int index = 0;
	const int end = 4;
	const char *result = slice(str, index, end);
	printf("%s\n", result);

	return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

char *substring( char *str, const int index, const int end)
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
		tmp[end] = '\0';
		tmp = tmp + index;
	}

	return tmp;
}

int main()
{
        char *str = "Arman";
	const int index = 1;
	const int end = 3;
	const char *result = substring(str, index, end);
	printf("%s\n", result);

	return 0;
}

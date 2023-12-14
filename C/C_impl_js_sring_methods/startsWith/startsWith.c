#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

bool startsWith(const char *str, const char *target, const int start_id)
{
	bool res = true;
	if (start_id < 0)
	{
		return false;
	}

	for (int i = start_id; i < strlen(target); ++i)
	{
		if (str[i + start_id] != target[i])
		{
			res = false;
		}
	}

	return res;

}

int main()
{
	const char *str = "hello world morld ";
	const char target[] = "ello ";
	const int start_id = 1;
	bool result = startsWith(str, target, start_id);
	printf("%d \n", result);

	return 0;
}

#include <stdio.h>

int *fill(int *arr, int size, int value, int start, int end)
{
	if (start == 0 && end == 0)
	{
		for (int i = 0; i < size; ++i)
		{
			arr[i] = value;
		}
	}

	if (end == 0)
	{
		for (int i = start; i < size; ++i)
		{
			arr[i] = value;
		}
	}
	else
	{
		for (int i = start; i < end; ++i)
		{
			arr[i] = value;
		}
	}

	return arr;
}

int main()
{
	int arr[] = { 1, 2, 3, 4 };

	int value = 5;
	int start = 1;
	int end = 0;
	int size = sizeof(arr) / sizeof(int);
	fill(arr, size, value, start, end);
	for (int i = 0; i < size; ++i)
	{
		printf("%d \n", arr[i]);
	}

	return 0;
}

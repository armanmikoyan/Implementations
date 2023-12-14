#include <stdio.h>

int indexOf(const int *arr, const int size, const int target)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == target)
		{
			return i;
		}
	}

	return -1;
}

int main()
{
	const int arr[] = { 1, -1, -1, -22, 3, 4, 5, 6, -7, 8, -9, 10 };

	const int size = sizeof(arr) / sizeof(int);
	const int target = 10;
	printf("%d \n", indexOf(arr, size, target));
	return 0;
}

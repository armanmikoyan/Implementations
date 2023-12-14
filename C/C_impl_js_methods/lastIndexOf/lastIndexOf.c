#include <stdio.h>

int lastIndexOf(const int *arr, const int size, const int target)
{
	int last_index = -1;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == target)
		{
			last_index = i;
		}
	}

	return last_index;
}

int main()
{
	const int arr[] = { 10, -1, -1, -22, 3, 4, 5, 6, -7, 8, -9, 10 };

	const int size = sizeof(arr) / sizeof(int);
	const int target = -1;
	printf("%d  \n", lastIndexOf(arr, size, target));
	return 0;
}

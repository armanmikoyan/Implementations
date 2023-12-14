#include <stdio.h>
#include <stdlib.h>

void reverse(int *arr, int size)
{
	int start = 0;
	int end = size - 1;
	while (start < end)
	{
		int tmp = arr[start];
		arr[start] = arr[end];
		arr[end] = tmp;
		start++;
		end--;
	}
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	int size = sizeof(arr) / sizeof(int);
	reverse(arr, size);
	for (int i = 0; i < size; ++i)
	{
		printf("%d \n", arr[i]);
	}

	return 0;
}

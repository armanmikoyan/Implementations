#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int *filter(signed int *arr, int **ptr_arr, int size, bool(*condition)(int))
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (condition(arr[i]))
		{
			count++;
		}
	}

	*ptr_arr = malloc(sizeof(int) *count);
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		if (condition(arr[i]))
		{ *(*ptr_arr + j) = arr[i];
			j++;
			printf("%d \n", arr[i]);
		}
	}

	return * ptr_arr;
}

bool condition(int elem)
{
	//condition
	return elem > 0;
}

int main()
{
	signed int arr[] = { -1, -1, -22, 3, 4, 5, 6, -7, 8, -9, 10 };

	int *filtered_arr;
	int size = sizeof(arr) / sizeof(int);
	filter(arr, &filtered_arr, size, condition);
	free(filtered_arr);
	return 0;
}

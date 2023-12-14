#include <stdio.h>
#include <stdlib.h>

int *map(const int arr[], int size, int(*condition)(int))
{
	int *tmp = malloc(size* sizeof(int));
	for (int i = 0; i < size; ++i)
	{
		tmp[i] = condition(arr[i]);
	}

	return tmp;
}

int condition(int elem)
{
	return elem * elem;
}

int main()
{
	const int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	int size = sizeof(arr) / sizeof(int);
	int *newArr = NULL;

	newArr = map(arr, size, condition);

	for (int i = 0; i < size; ++i)
	{
		printf("%d - %d \n", arr[i], newArr[i]);
	}

	free(newArr);

	return 0;
}

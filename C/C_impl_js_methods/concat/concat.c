#include <stdio.h>
#include <stdlib.h>

void concat(int *arr1, int *arr2, int arr1_len, int arr2_len, int **concated_arr)
{
	*concated_arr = (int*) malloc((arr1_len + arr2_len) *sizeof(int));
	for (int i = 0; i < arr1_len; ++i)  // for copying arr1 elems to concated array
	{
		*(*concated_arr + i) = *(arr1 + i);
	}

	for (int i = arr1_len; i < arr1_len + arr2_len; ++i) // for copying arr2 elems to concated array
	{
		*(*concated_arr + i) = *(arr2 + i - arr1_len);
	}

	for (int i = 0; i < arr1_len + arr2_len; ++i) //for printing concated array on the screen 
	{
		printf("%d \n", *(*concated_arr + i));
	}
}

int main()
{
	int *concated_arr;
	int arr1[] = { 1, 2, 3, 4, 5 };

	int arr1_len = sizeof(arr1) / sizeof(int);
	int arr2[] = { 6, 7, 8, 9, 10 };

	int arr2_len = sizeof(arr2) / sizeof(int);
	concat(arr1, arr2, arr1_len, arr2_len, &concated_arr);
	free(concated_arr);

	return 0;
}

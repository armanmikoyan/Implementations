#include <stdio.h>
#include <stdlib.h>

int *sliceByIndex(int *arr, int id1, int size, int *newArr)
{
	newArr = &arr[id1];
	return newArr;

}

int *sliceByRange(int *arr, int id1, int id2, int size, int *newArr)
{
	for (int i = 0; i < id2; ++i)
	{
		newArr[i] = arr[id1];
		id1++;
	}

	return newArr;

}

int main()
{
	int id1 = 1;
	int id2 = 8;
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	int size = sizeof(arr) / sizeof(int); // SIZE ORIGINAL ARRAY

	int size_for_id = size - id1;       // SIZE SPLITED ARRAY BY ID

	int size_for_range = id2 - id1;     //SIZE SPLITED ARRAY BY RANGE

	int *sliceId = malloc((size - id1) *sizeof(int));
	sliceId = sliceByIndex(arr, id1, size, sliceId);

	int *sliceRange = malloc((id2 - id1) *sizeof(int));
	sliceRange = sliceByRange(arr, id1, id2, size, sliceRange);

/*	for (int i = 0; i < size_for_range; ++i)
	{
		                                           // print sliced array by range
		printf(" %d \n", sliceRange[i]);
	}
*/
/*	for (int i = 0; i < size_for_id; ++i)
	{
		                                           // print sliced array by id
		printf(" %d \n", sliceId[i]);
	}
*/        

	return 0;
}

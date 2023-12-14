#include <stdio.h>
#include <stdlib.h>

struct Entries
{
	int id;
	int val;
};

struct Entries* entries(int *arr, int size)
{
	struct Entries *entry = malloc(size* sizeof(entries));
	for (int i = 0; i < size; ++i)
	{
		entry[i].id = i;
		entry[i].val = arr[i];
	}

	return entry;
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };

	int size = sizeof(arr) / sizeof(int);
	struct Entries *entry = entries(arr, size);

	for (int i = 0; i < size; ++i)
	{
		printf("id-> %d value-> %d \n", entry[i].id, entry[i].val);
	}

	return 0;
}

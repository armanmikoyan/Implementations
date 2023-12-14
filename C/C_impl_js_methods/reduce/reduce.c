#include <stdio.h>
#include <stdlib.h>

int reduce(const int arr[], int size, int(*reductor)(int, int), int initialVal)
{
	int tmp = initialVal;
	for (int i = 0; i < size; ++i)
	{
		tmp = reductor(tmp, arr[i]);
	}

	return tmp;
}

int add(int acum, int current)
{
	return acum + current;
}

int mul(int acum, int current)
{
	return acum * current;
}

int main()
{
	const int arr[] = { 1, 2, 3, 4 };

	int initialVal = 0;
	int size = sizeof(arr) / sizeof(int);
	int sum_of_all = reduce(arr, size, add, initialVal);
	int mul_all_digits = reduce(arr, size, mul, 1);

	printf("add-> %d  \n", sum_of_all);
	printf("mul-> %d  \n", mul_all_digits);
	return 0;
}

#include <stdio.h>
#include <stdbool.h>

bool some(signed int *arr, int size, bool(*condition)(int))
{
	for (int i = 0; i < size; ++i)
	{
		if (condition(arr[i]))
		{
			printf("true \n");
			return true;
		}
	}

	printf("false \n");
	return false;
}

bool condition(int elem)
{
	//condition
	return elem < 0;
}

int main()
{
        signed int arr[] = {1,1,2,3,4,5,6,-7,8,9,10};

	int size = sizeof(arr) / sizeof(int);

	printf("%d \n", some(arr, size, condition));
	return 0;
}

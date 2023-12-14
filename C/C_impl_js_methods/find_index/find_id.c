#include <stdio.h>
#include <stdbool.h>

int find(int *arr, int size, bool(*f_ptr)(int))
{
  for (int i = 0; i < size; ++i)
  {
    if (f_ptr(arr[i]))
    {
      return i;
    }
  }

  return -1;
}

bool f_ptr(int elem)
{
  if (elem > 6)
  {
    return true;
  }

  return false;
}

int main()
{
  int arr[] = { 1, 2, 3, 4, 5, 6, 7 };

  int size = sizeof(arr) / sizeof(int);
  printf("%d \n", find(arr, size, f_ptr));

  return 0;
}

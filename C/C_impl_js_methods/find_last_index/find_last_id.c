#include <stdio.h>
#include <stdbool.h>

int find(int *arr, int size, bool(*f_ptr)(int))
{
int tmp = -1;
  for (int i = 0; i < size; ++i)
  {
    if (f_ptr(arr[i]))
    {
     tmp = i;
    }

  }

  return tmp;
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
  int arr[] = { 10,20, 90, 50, 1};

  int size = sizeof(arr) / sizeof(int);
  printf("%d \n", find(arr, size, f_ptr));

  return 0;
}

#include <stdio.h>
#include <stdbool.h>

int find(int *arr, int size,int target, bool(*f_ptr)(int,int))
{
  for (int i = 0; i < size; ++i)
  {
    if (f_ptr(arr[i],target))
    {
      printf("true \n");
      return true;
    }
  }
  printf("false \n");
  return -1;
}

bool f_ptr(int elem, int target)
{
  if (elem == target)
  {
    return true;
  }

  return false;
}

int main()
{
  int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
  int target = 7;
  int size = sizeof(arr) / sizeof(int);
  printf("%d \n", find(arr, size,target, f_ptr));

  return 0;
}

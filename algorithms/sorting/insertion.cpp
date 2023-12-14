#include <iostream>

void insertion_sort(int* arr, int n)
{
  for (int i = 1; i < n; ++i)
  {
      int key = arr[i];
      int j = i - 1;
      while (j >= 0 && key < arr[j])
      {
        arr[j + 1] = arr[j];
        --j;
      }
      arr[j + 1] = key;
  }
}


int main() 
{
  int arr[] = {5, 1, 7, 7, 8, 2, 10, 99, 3, 4};
  int size = sizeof(arr) / sizeof(int);
  insertion_sort(arr, size);
  for(auto it : arr)
  {
    std::cout << it << " ";
  }
  std::cout << std::endl;
}

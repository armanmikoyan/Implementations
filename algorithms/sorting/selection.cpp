#include <iostream>

void selection(int* arr, int size)
{
  for (int i = 0; i < size - 1; ++i)
  {
    int min = i;
    for (int j = i + 1; j < size; ++j)
    {
      if (arr[j] < arr[min])
      {
        min = j;
      }
    }
    int tmp = arr[i];
    arr[i] = arr[min];
    arr[min] = tmp;
  }
}


int main() 
{
   int arr[11]{2, 3, 2, 1, 4, 6, 4, 2, 3, 6, 9};
   int size = sizeof(arr) / sizeof(int);
   selection(arr,size);
   for(auto it : arr)
   {
     std::cout << it << " ";
   }
} 

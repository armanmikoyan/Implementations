#include <iostream>

void bubble(int* arr, int size)
{
  for(int i = 0; i < size - 1; ++i)
  {
    for(int j = 0; j < size - i - 1; ++j)
    {
      if (arr[j] > arr[j + 1])
      {
        int tmp = arr[j + 1];
        arr[j + 1] = arr[j];
        arr[j] = tmp;
      }
    }
  
  }
}


int main() 
{
   int arr[11]{2, 3, 2, 1, 4, 6, 4, 2, 3, 6, 9};
   int size = sizeof(arr) / sizeof(int);
   bubble(arr,size);
   for(auto it : arr)
   {
     std::cout << it << " ";
   }
} 

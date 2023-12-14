#include <iostream>


int b_search(int* arr, int size, int target)
{
  int left = 0;
  int right = size - 1;
  while (left <= right)
  {
    int mid = left + (right - left ) / 2;
    if (arr[mid] == target)
    {
      return mid;
    }
    else if (arr[mid] > target)
    {
      right = mid - 1;
    }
    else 
    {
      left = mid + 1;
    }
  }
  return - 1;
}

int main() 
{
   int arr[]{1, 2, 3, 4, 5, 6, 7, 8, 9};
   int size = sizeof(arr) / sizeof(int);
   int target = 6;
   int res = b_search(arr, size, target);
   std::cout << res << "\n";
} 

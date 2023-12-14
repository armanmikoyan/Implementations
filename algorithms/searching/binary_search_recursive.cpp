#include <iostream>


int b_search(int* arr, int target, int left, int right)
{
  int mid = left + (right - left) / 2;
  if(left <= right)
  {
      if (arr[mid] == target)
      {
        return mid;
      }
      else if (arr[mid] > target)
      {
        return b_search(arr, target, left, mid - 1);
      }
      else 
      {
        return b_search(arr, target, mid + 1, right);
      }
  }

  return - 1;
}


int main() 
{
   int arr[]{1, 2, 3, 4, 5, 6, 7, 8, 9};
   int size = sizeof(arr) / sizeof(int);
   int left = 0;
   int right = size - 1;
   int target = 8;
   int res = b_search(arr, target, left, right);
   std::cout << res << "\n";
} 

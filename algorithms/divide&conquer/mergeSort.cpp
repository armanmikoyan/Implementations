#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, int start, int mid, int end)
{  
   //first subarray
   int st1 = start;
   int en1 = mid;

   //second subarray
   int st2 = mid + 1;
   int en2 = end;

   std::vector<int> tmp = arr;
   int k = start;

   while (st1 <= en1 && st2 <= en2)
   {
      if (arr[st1] < arr[st2])
      {
         tmp[k++] = arr[st1++];
      }
      else
      {
         tmp[k++] = arr[st2++];
      }
   }

   while (st1 <= en1)
   {
      tmp[k++] = arr[st1++];
   }

   while (st2 <= en2)
   {
      tmp[k++] = arr[st2++];
   }

   for (int i = start; i <= end; ++i)
   {
      arr[i] = tmp[i];
   }

}

void mergeSort(std::vector<int>& arr, int start, int end)
{
   int mid = start + (end - start) / 2;
  
   if (start < end)
   {
      mergeSort(arr, start, mid);
      mergeSort(arr, mid + 1, end);
      merge(arr, start, mid , end);
   }
}

int main() 
{
   std::vector<int> arr{4, 2, 1, 4, 5, 6, 4, 9};
   int size = arr.size();
   mergeSort(arr, 0, size - 1);

   for (auto it : arr)
   {
       std::cout << it << " ";
   }
 
} 

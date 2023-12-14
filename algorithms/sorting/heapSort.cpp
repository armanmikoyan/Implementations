#include <iostream>
#include <vector>

void heapify(std::vector<int>& arr, int n, int i)
{
   size_t left =  2 * i + 1;
   size_t right = 2 * i + 2;
   size_t largest =       i;

   if (left < n && arr[left] > arr[largest])
   {
      largest = left;
   }

   if (right < n && arr[right] > arr[largest])
   {
      largest = right;
   }

   if (largest != i)
   {
      std::swap(arr[i], arr[largest]);
      heapify(arr, n, largest);
   }
}

void heapsort(std::vector<int>& arr)
{
   int n = arr.size();
   for (int i = n / 2 - 1; i >=0; --i)
   {
      heapify(arr, n, i);
   }

   for (int i = n - 1; i >= 0; --i)
   {
      std::swap(arr[0], arr[i]);
      n--;
      heapify(arr, n, 0);
   }
}

int main()
{
   std::vector<int> v {2, 1, 99, 8, 6, 4, -1, 2};
   heapsort(v);
   for (auto it : v)
   {
     std::cout << it << " ";
   }
   std::cout << std::endl;
}
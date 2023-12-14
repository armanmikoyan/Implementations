#include "max_heap.hpp"

maxheap::maxheap(std::initializer_list<int> list)
{
   _heap_size = list.size();
   for (auto it = list.begin(); it != list.end(); ++it)
   {
      _arr.push_back(*it);
   }
   build();
}

size_t maxheap::get_parent(size_t i) const
{
   if (i == 0) return 0;
   return (i - 1) / 2;
}

size_t maxheap::get_left_child(size_t i) const
{
   return (2 * i) + 1;
}

size_t maxheap::get_right_child(size_t i) const
{
   return (2 * i) + 2;
}

void maxheap::heapify(size_t i)
{
   size_t left =   get_left_child(i);
   size_t right = get_right_child(i);
   size_t largest = i;

   if (left < _heap_size && _arr[left] > _arr[largest])
   {
      largest = left;
   }

   if (right < _heap_size && _arr[right] > _arr[largest])
   {
      largest = right;
   }

   if (largest != i)
   {
      std::swap(_arr[largest], _arr[i]);
      heapify(largest);
   }
}

void maxheap::build()
{
   for (int i = (_heap_size / 2) - 1; i >= 0; --i)
   {
      heapify(i);
   }
}

void maxheap::extract_max() 
{
   if (_heap_size == 1) return;
   std::swap(_arr[0], _arr[_heap_size - 1]);
   --_heap_size;
   heapify(0);  
}

void maxheap::sort()
{
   while(_heap_size != 1)
   {
      extract_max();
   }
}
void maxheap::traverse_heap()
{
   std::cout <<  "heap\n";
   for (int i = 0; i < _heap_size; ++i)
   {
      std::cout << _arr[i] << " ";
   }
   std::cout << std::endl;
}

void maxheap::traverse_all()
{
   std::cout << "all\n";
   for (int i = 0; i < _arr.size(); ++i)
   {
      std::cout << _arr[i] << " ";
   }
   std::cout << std::endl;
}
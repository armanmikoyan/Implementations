#ifndef MINHEAP
#define MINHEAP

#include <vector>
#include <iostream>

class minheap
{
public:
   minheap(std::initializer_list<int>);
   
public:
   void traverse_heap();
   void  traverse_all();
   void          sort();

private:
   void                   extract_max();
   void               heapify(size_t i);
   void                         build();
   size_t  get_left_child(size_t) const;
   size_t get_right_child(size_t) const;
   size_t      get_parent(size_t) const;

private:
   std::vector<int> _arr;
   size_t _heap_size;
};

#endif //MINHEAP
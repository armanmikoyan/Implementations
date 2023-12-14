#ifndef PQUEUE
#define PQUEUE

#include <vector>
#include <algorithm>
#include <iostream>

// queue value type  is  pair <int, T> T can be anyting

template<typename T, typename Compare = std::greater<std::pair<int, T>>> 
class priority_queue
{   
public:
   void     insert(std::pair<int,T>);
   void                    extract();
   void decrease_key(size_t, size_t);
   void increase_key(size_t, size_t);
   void             traverse_queue();
   void             traverse_array();


private:
   void               heapify(size_t i);
   void                         build();
   size_t  get_left_child(size_t) const;
   size_t get_right_child(size_t) const;
   size_t      get_parent(size_t) const;

private:
   std::vector<std::pair<int, T>> _arr;
   Compare _cmp;
   size_t _queue_size = 0;
};

#include "priority_queue.tpp"

#endif //PQUEUE
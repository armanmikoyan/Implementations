template<typename T, typename Compare>
size_t priority_queue<T, Compare>::get_parent(size_t i) const
{
   if (i == 0) return 0;
   return (i - 1) / 2;
}

template<typename T, typename Compare>
size_t priority_queue<T, Compare>::get_left_child(size_t i) const
{
   return (2 * i) + 1;
}

template<typename T, typename Compare>
size_t priority_queue<T, Compare>::get_right_child(size_t i) const
{
   return (2 * i) + 2;
}

template<typename T, typename Compare>
void priority_queue<T, Compare>::heapify(size_t i)
{
   size_t left =   get_left_child(i);
   size_t right = get_right_child(i);
   size_t selected = i;

   if (left < _queue_size && _cmp(_arr[left], _arr[selected]))
   {
      selected = left;
   }

   if (right < _queue_size && _cmp(_arr[right], _arr[selected]))
   {
      selected = right;
   }

   if (selected != i)
   {
      std::swap(_arr[selected], _arr[i]);
      heapify(selected);
   }
}

template<typename T, typename Compare>
void priority_queue<T, Compare>::build()
{
   for (int i = (_queue_size / 2) - 1; i >= 0; --i)
   {
      heapify(i);
   }
}

template<typename T, typename Compare>
void priority_queue<T, Compare>::insert(std::pair<int, T> el)
{
   _arr.push_back(el);
   ++_queue_size;
   size_t index = _queue_size - 1;
   while (index > 0 && _cmp(el, _arr[get_parent(index)]))
   {
      std::swap(_arr[index], _arr[get_parent(index)]);
      index = get_parent(index);
   }
}

template<typename T, typename Compare>
void priority_queue<T, Compare>::extract()
{
   std::swap(_arr[0], _arr[_queue_size - 1]);
   --_queue_size;
   heapify(0);
}

template<typename T, typename Compare>
void priority_queue<T, Compare>::decrease_key(size_t id, size_t val)
{
   if (id >= _queue_size) throw std::out_of_range("id greater then queue");

   _arr[id].first -= val;
   if constexpr (std::is_same_v<Compare, std::less<std::pair<int,T>>>)
   {
      while (id >= 0 && _cmp(_arr[id], _arr[get_parent(id)]))
      {
         std::swap(_arr[id], _arr[get_parent(id)]);
         id = get_parent(id);
      }
   }
   else
   {
      heapify(id);
   }
}

template<typename T, typename Compare>
void priority_queue<T, Compare>::increase_key(size_t id, size_t val)
{
   if (id >= _queue_size) throw std::out_of_range("id greater then queue");
   _arr[id].first += val;

   if constexpr (std::is_same_v<Compare,std::less<std::pair<int,T>>>)
   {
      heapify(id);
   }
   else
   {
      while (id >= 0 && _cmp(_arr[id], _arr[get_parent(id)]))
      {
         std::swap(_arr[id], _arr[get_parent(id)]);
         id = get_parent(id);
      }
   }
}

template<typename T, typename Compare>
void priority_queue<T, Compare>::traverse_array()
{
   std::cout << "all array\n";
   for (int i = 0; i < _arr.size(); ++i)
   {
      std::cout << "index: " <<  i << " " << _arr[i].first << " val: "<< _arr[i].second << "\n";
   }
   std::cout << std::endl;
}

template<typename T, typename Compare>
void priority_queue<T, Compare>::traverse_queue()
{
   std::cout << "queue\n";
   for (int i = 0; i < _queue_size; ++i)
   {
      std::cout << "queue " << i + 1 << " ";
      std::cout << "priority: "  << _arr[i].first << " val: "<< _arr[i].second << "\n";
   }
   std::cout << std::endl;
}


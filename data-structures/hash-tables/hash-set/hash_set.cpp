hash_set::hash_set()
     : _table{generate_prime_size()}
     , _elem_count{}
{
     _table_size = generate_prime_size();
}

size_t hash_set::hash(int elem, int sz) const
{
     return elem % sz;
}

void hash_set::insert(int elem)
{
     int key = hash(elem);
     _table[key].push_front(elem);
     _elem_count++;
     if ((static_cast<float>(_elem_count) / _table_size) >= _load_factor)
     {
          rehash();
     }
}

bool hash_set::operator[](int elem) const
{
     return contains(elem);
}

bool hash_set::contains(int elem) const
{
   int key = hash(elem);
   for (auto it = _table[key].begin(); it != _table[key].end(); ++it)
   {
        if (*it == elem) return true;
   }
   return false;
}

void hash_set::erase(int elem)
{
     int key = hash(elem);
     std::forward_list<int>& list = _table[key];
     list.remove_if([elem, this](int value){
          if (elem == value)
          {
               _elem_count--;
               return true;
          }
          return false;
     });
}

void hash_set::rehash()
{
     _table_size = generate_prime_size(_table_size);
     std::vector<std::forward_list<int>> new_table(_table_size);

     for (const auto& table_id : _table)
     {
          for (const auto& elem : table_id)
          {
               int key = hash(elem, _table_size);
               new_table[key].push_front(elem);
          }
     }

     _table.clear();
     _table = std::move(new_table);
}

void hash_set::traverse()
{
     for(int i = 0; i < _table.size(); ++i)
     {
          std::cout << "Id-" << i << ": ";
          for(const auto& elem : _table[i])
          {
               std::cout << elem << " -> ";
          }
          std::cout << std::endl;
     }     
}
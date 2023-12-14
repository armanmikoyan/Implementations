template<typename T>
hash_map<T>::hash_map()
     : _table{generate_prime_size()}
     , _elem_count{}

{
     _table_size = generate_prime_size();
}

template<typename T>
size_t hash_map<T>::hash(const std::string& key, int sz) const
{
     size_t res{};
     for (int i = 0; i < key.size(); ++i)
     {
          res += static_cast<int>(key[i]);
     }
     res += key[0] - key[key.size() - 1];
     return res % sz;
}

template<typename T>
T& hash_map<T>::operator[](const std::string& key)
{
     size_t hashed_key = hash(key);
     for (auto& elem : _table[hashed_key])
     {
          if (elem.first == key)
          {
               return elem.second;
          }
     }
     _table[hashed_key].emplace_front(key, T());
     _elem_count++;
     if ((static_cast<float>(_elem_count) / _table_size) >= _load_factor)
     {
          rehash();
          hashed_key = hash(key);

     }
     for (auto& elem : _table[hashed_key])
     {
          if (elem.first == key)
          {
               return elem.second;
          }
     }
     throw std::logic_error("undefiend");
}

template<typename T>
void hash_map<T>::erase(const std::string& elem)
{
     int key = hash(elem);    
     std::forward_list< std::pair<std::string, T>>& list = _table[key];
     list.remove_if([elem,this](std::pair<std::string, T> vals){
          if (vals.first == elem)
          {
               --_elem_count;
               return true;
          }
          return false;
     });
}

template<typename T>
bool hash_map<T>::contains(const T& val) const
{
     for(auto& idx : _table)
     {
          for(auto elem : idx)
          {
               if(elem.second == val) return true;
          }
     }
     return false;
}

template<typename T>
void hash_map<T>::hash_map::rehash()
{
     _table_size = generate_prime_size(_table_size);
     std::vector<std::forward_list<std::pair<std::string, T>>> new_table(_table_size);
     for (auto& idx : _table)
     {
          for (auto& elems : idx)
          {
               size_t hashed_key = hash(elems.first);
               new_table[hashed_key].emplace_front(elems);
          }
     }
     _table.clear();
     _table = std::move(new_table); 
}

template<typename T>
void hash_map<T>::traverse()
{
     for (int i = 0; i < _table.size(); ++i)
     {
          std::cout << "Id-" << i << ": ";
          for (const auto& elem : _table[i])
          {
               std::cout << elem.second << " -> ";
          }
          std::cout << std::endl;
     }     
}
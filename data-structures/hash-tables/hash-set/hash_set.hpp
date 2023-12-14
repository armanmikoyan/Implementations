#ifndef HASH_SET
#define HASH_SET

#include <vector>
#include <forward_list>
#include <iostream>
#include "../table_size_generator/generate.hpp"

class hash_set
{
public:
     hash_set();

public:
     void           insert(int);
     bool    contains(int)const;
     bool operator[](int) const;
     void            erase(int);
     void            traverse();

private:
     size_t hash(int, int sz = _table_size) const;
     void                                rehash();

private:
     std::vector<std::forward_list<int>> _table;
     static constexpr float  _load_factor = 0.7;
     size_t                         _elem_count;
     static inline size_t           _table_size;
};

#include "hash_set.cpp"
#endif //HASH_SET
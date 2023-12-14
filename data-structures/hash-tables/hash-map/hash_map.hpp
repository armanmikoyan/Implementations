#ifndef HASH_SET
#define HASH_SET

#include <vector>
#include <forward_list>
#include <string>
#include <utility>
#include <iostream>
#include "../table_size_generator/generate.hpp"

// key only can be string, value can be any type

template<typename T>
class hash_map
{
public:
     hash_map();

public:
     bool       contains(const T&) const;
     T&   operator[](const std::string&);
     void      erase(const std::string&);
     void                     traverse();

private:
     size_t hash(const std::string&, int sz = _table_size) const;
     void                                               rehash();

public:
     std::vector<std::forward_list<std::pair<std::string, T>>> _table;
     static constexpr float                        _load_factor = 0.7;
     size_t                                               _elem_count;
     static inline size_t                                 _table_size;
};

#include "hash_map.tpp"
#endif //HASH_SET
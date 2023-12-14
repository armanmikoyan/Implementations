#ifndef LIST
#define LIST

#include <iostream>

template<typename T>
class list
{   
public:
     using value_type =                                T;
     using reference =                                T&;
     using const_reference =                    const T&;
     using pointer =                                  T*;
     using const_pointer =                      const T*;
     using difference_type =              std::ptrdiff_t;
     using iterator_category = std::forward_iterator_tag;

private:
     struct Node 
     {
     public:
          T        _data;
          Node*    _next;
     public:

          Node        ();
          Node(const T&);
     };

private:
     Node* _head;

public:
     list                          ();
    ~list                          ();
     list               (const list&);
     list(list&&)            noexcept;
     list&     operator=(const list&);
     list& operator=(list&&) noexcept;

public:
     void                 traverse();
     void        push_back(const T&);
     void       push_front(const T&);
     void                 pop_back();
     void                pop_front();
     bool       search(const T& val);
     void   insert(size_t, const T&);
     void              erase(size_t);
     void                  reverse();
     Node*                     mid();

public:
     class const_iterator
     {
     public:
          const_iterator(Node*);
     public:
          const_reference            operator*() const;
          const_iterator&                 operator++();
          const_iterator               operator++(int);
          const_iterator                operator+(int);
          bool operator==(const const_iterator&) const;
          bool operator!=(const const_iterator&) const;
          
     private:
          const Node* _current;
     };

     class iterator
     {
     public:
          iterator(Node*);
     public:
          reference            operator*() const;
          iterator&                 operator++();
          iterator               operator++(int);
          iterator                operator+(int);
          bool operator==(const iterator&) const;
          bool operator!=(const iterator&) const;
          
     private:
          Node* _current;
     };

     public:
          const_iterator cbegin();
          const_iterator   cend();
          iterator        begin();
          iterator          end();
};

#include "iterator.tpp"
#include "list.tpp"
#endif //LIST
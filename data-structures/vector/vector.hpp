#ifndef VECTOR_H
#define VECTOR_H

template <typename T>
class vector 
{
public:
     class       iterator;
     class const_iterator;

public:
     using value_type =                                      T;
     using reference =                                      T&;
     using const_reference =                          const T&;
     using pointer =                                        T*;
     using const_pointer =                            const T*;
     using difference_type =                    std::ptrdiff_t;
     using iterator_category = std::random_access_iterator_tag;

public:
     vector                            ();  
    ~vector                            ();
     vector                      (size_t); 
     vector           (const vector& oth); 
     vector    (std::initializer_list<T>); 
     vector& operator=    (const vector&);
     vector(vector&& oth)        noexcept; 
     vector& operator=(vector&&) noexcept; 
 
public:
     void             traverse() const;
     void          push_back(const T&);
     void                   pop_back();
     void      insert(size_t,const T&);
     size_t                  search(T);
     void               resize(size_t);
     void          erase(iterator pos);
     T                      at(size_t);
     T&             operator[](size_t);
     const T& operator[](size_t) const;
     size_t               size() const;

private:
     T*          _arr;
     size_t     _size;
     size_t _capacity;

public:
     class iterator
     {
     public:
          iterator(T*);

     public:
          reference            operator*() const;
          iterator&                 operator++();
          iterator&                 operator--();
          iterator               operator++(int);
          iterator               operator--(int);
          iterator                operator+(int);
          bool operator==(const iterator&) const;
          bool operator!=(const iterator&) const;

     private:
          T* _current;
     };
     class const_iterator
     {
     public:
          const_iterator(const T*);
     public:
          const_reference            operator*() const;
          const_iterator&                 operator++();
          const_iterator&                 operator--();
          const_iterator               operator++(int);
          const_iterator               operator--(int);
          const_iterator                operator+(int);
          bool operator==(const const_iterator&) const;
          bool operator!=(const const_iterator&) const;
     private:
          const T* _current;
     };
public:
     iterator              begin();
     iterator                end();
     const_iterator cbegin() const;
     const_iterator   cend() const;
};
#include "vector.tpp"
#include "iterator.tpp"		
#endif  // VECTOR_H 








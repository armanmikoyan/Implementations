#ifndef SHARED
#define SHARED

#include <iostream>

template<typename T>
struct Control_block
{
    T* _ptr;
    size_t* ref_count;
    size_t* weak_count;
    Control_block();
   ~Control_block();
};

template<typename T>
class shared_ptr 
{
public:
     ~shared_ptr();
     shared_ptr(T* p = nullptr, void(*)(T*) = nullptr);
     shared_ptr(const shared_ptr& oth);
     shared_ptr(shared_ptr&& oth) noexcept;
     shared_ptr& operator=(const shared_ptr& oth);
     shared_ptr& operator=(shared_ptr&& oth) noexcept;

public:
     T* get();
     T* operator->();
     T& operator*();

private:
     void deleting();

private:
     Control_block<T>* _control_block;
     void (*_deleter)(T*);
};



#include "shared_ptr.tpp"

#endif //SHARED
#ifndef UNIQUE
#define UNIQUE

#include <iostream>

template<typename T, typename Deleter = std::nullptr_t>
class unique_ptr 
{
public:
     unique_ptr(T* ptr = nullptr, Deleter deleter = Deleter());
    ~unique_ptr();
     unique_ptr(unique_ptr&& oth) noexcept;
     unique_ptr& operator=(unique_ptr&& oth) noexcept;

public:
     void reset(T* optional = nullptr);
     T* operator->();
     T& operator*();
     T* release();
     T* get();

private:
     unique_ptr(const unique_ptr&)            = delete;
     unique_ptr& operator=(const unique_ptr&) = delete;

private:
     T* _ptr;
     Deleter _deleter;
};

#include "unique_ptr.tpp"

#endif //UNIQUE
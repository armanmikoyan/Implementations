#ifndef STACK
#define STACK

#include <vector>
#include <iomanip>

template<typename T>
class stack
{       
public:
     using value_type =             T;
     using reference =             T&;
     using const_reference = const T&;
     
public:
     stack                           ();
     stack               (const stack&);
     stack           (stack&&) noexcept;
     stack& operator=(stack&&) noexcept;
     stack&     operator=(const stack&);

public:
     bool   empty() const;
     size_t  size() const;
     void  push(const T&);
     void           pop();
     const T& top() const;
     
private:
     std::vector<T> _data;
     T               _top;
};

#include "stack.tpp"
#endif //STACK
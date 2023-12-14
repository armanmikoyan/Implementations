#ifndef QUEUE
#define QUEUE

#include <vector>

template<typename T>
class queue
{      
public:
     using value_type =             T;
     using reference =             T&;
     using const_reference = const T&;

public:
     queue                           ();
     queue               (const queue&);
     queue           (queue&&) noexcept;
     queue& operator=(queue&&) noexcept;
     queue&     operator=(const queue&);

public:
     bool     empty() const;
     size_t    size() const;
     void    push(const T&);
     void             pop();
     const T& front() const;
     const T&  back() const;
     
private:
     std::vector<T> _data;
     T               _top;
};

#include "queue.tpp"
#endif // QUEUE
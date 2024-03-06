#ifndef SLL
#define SLL

#include <iostream>
#include <memory>

template<typename T>
class sll
{       
public:
    using value_type =             T;
    using reference =             T&;
    using const_reference = const T&;
    using pointer =               T*;
    using const_pointer =   const T*;
    
private:
     struct Node 
     {
        Node(const T& elm = T{}) : data{elm}, next{}, prev{} {}
        ~Node(){ std::cout << "Deleted node: " << data << "\n"; }

        T                     data;
        std::shared_ptr<Node> next;
        std::weak_ptr<Node>   prev;
     };

public:
    sll() : head{}, tail{} {}
    ~sll() = default;

private:
    std::shared_ptr<Node> head;
    std::weak_ptr<Node>   tail;

public:
    void                   print();
    void       push_back(const T&);
    void      push_front(const T&);
    void                pop_back();
    void               pop_front();
    void  insert(size_t, const T&);
    void             erase(size_t);
};

#include "smart.tpp"
#endif //SLL
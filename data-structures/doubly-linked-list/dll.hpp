#ifndef DLL
#define DLL
#include <iostream>

template<typename T>
class dll
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
     public:
        T        _data;
        Node*    _next;
        Node*    _prev;
        Node        ();
        Node(const T&);
     };

private:
    Node* _head;
    Node* _tail;

public:
    dll                         ();
   ~dll                         ();
    dll               (const dll&);
    dll(dll&&)            noexcept;
    dll&     operator=(const dll&);
    dll& operator=(dll&&) noexcept;

public:
    void                traverse();
    void       push_back(const T&);
    void      push_front(const T&);
    void                pop_back();
    void               pop_front();
    bool          search(const T&);
    void  insert(size_t, const T&);
    void             erase(size_t);
    void                 reverse();
    Node*                    mid();
};

#include "dll.tpp"
#endif //DLL
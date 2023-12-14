#ifndef SOLL
#define SOLL

#include <iostream>

template<typename T>
class soll
{
public:
    using value_type =             T;
    using reference =             T&;
    using const_reference = const T&;
    using pointer =               T*;
    using const_pointer =   const T*;

public:
    soll                          ();
   ~soll                          ();
    soll               (const soll&);
    soll           (soll&&) noexcept;
    soll&     operator=(const soll&);
    soll& operator=(soll&&) noexcept;

public:
    void                traverse();
    void       push_back(const T&);
    void      push_front(const T&);
    void                pop_back();
    void               pop_front();
    bool          search(const T&);
    void  insert(size_t, const T&);
    void             erase(size_t);

private:
    struct Node 
    {
    public:
        T        _data;
        Node*    _next;
        Node*    _prev;
        Node*     _asc;
        Node*    _desc;
        Node        ();
        Node(const T&);
    };

private:
    void    asc_desc_new_node(Node*);
    void asc_desc_exsist_node(Node*);
    void              promote(Node*);

private:
    Node*      _head;
    Node*      _tail;
    Node*  _asc_head;
    Node* _desc_head;
};

#include "soll.tpp"
#endif //SOLL   
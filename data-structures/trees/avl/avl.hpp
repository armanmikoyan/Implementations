#ifndef AVL
#define AVL

#include <queue>
#include <stack>
#include <iostream>

template<typename T>
class avl
{      
private:
    class node 
    {
    public:
        node ();
        node(T);

    public:
        node*  _left;
        node* _right;
        T       _val;
    };  

public:
    avl();

public: //interface 
    void level_order_traversal() const;
    void         traverse_post() const;
    void          traverse_pre() const;
    void           traverse_in() const;
    bool               search(T) const;
    void                     insert(T);
    void                      erase(T);

private: // helpers  
    void level_order_traversal_r(node*, int) const;
    void              traverse_post_r(node*) const;
    void               traverse_pre_r(node*) const; 
    void                traverse_in_r(node*) const;
    bool                  search_r(node*, T) const;
    int                balance_factor(node*) const;
    node*                 predecessor(node*) const;
    node*                   successor(node*) const; 
    node*                   get_max_r(node*) const;
    node*                   get_min_r(node*) const; 
    int                       depth_r(node*) const;
    node*                      right_rotate(node*); 
    node*                       left_rotate(node*);
    node*                       insert_r(node*, T);
    node*                        erase_r(node*, T); 

private:
    node* _root;
};

#include "avl.tpp"
#endif //AVL
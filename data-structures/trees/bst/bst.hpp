#ifndef BST
#define BST

#include <vector>
#include <queue>
#include <stack>
#include <iostream>

template<typename T>
class bst
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
    bst();

public: //interface 
    void level_order_traversal() const;
    void         traverse_post() const;
    void          traverse_pre() const;
    void           traverse_in() const;
    bool               search(T) const;
    void                     insert(T);
    void                      erase(T);

private: // recursive  impl
    void level_order_traversal_r(node*, int) const;
    void              traverse_post_r(node*) const;
    void               traverse_pre_r(node*) const; 
    void                traverse_in_r(node*) const;
    bool                  search_r(node*, T) const;
    node*                   get_max_r(node*) const; 
    node*                   get_min_r(node*) const; 
    int                       depth_r(node*) const;
    node*                       insert_r(node*, T);
    node*                        erase_r(node*, T); 

private: // iterative  impl
    void level_order_traversal_i() const;
    void         traverse_post_i() const;// --
    void          traverse_pre_i() const;// --
    void           traverse_in_i() const;
    node*       predecessor(node*) const; 
    node*         successor(node*) const; 
    node*         get_min_i(node*) const; 
    node*         get_max_i(node*) const;
    bool               search_i(T) const;
    int                  depth_i() const;// --
    void                     insert_i(T);

private:
    node* _root;
};

#include "bst.tpp"
#endif //BST
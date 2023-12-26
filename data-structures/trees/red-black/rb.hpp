#ifndef RB
#define RB

#include <queue>
#include <stack>
#include <iomanip>
#include <iostream>

template<typename T>
class rb
{      
private:
    enum class color
    {
        red,
        black
    };
    class node
    {
    public:
        node ();
        node(T);

    public:
        node* _parent;
        node*   _left;
        node*  _right;
        color  _color;
        T        _val;
    };  

public:
    rb();

public: //interface 
    void level_order_traversal() const;
    void         traverse_post() const;
    void          traverse_pre() const;
    void           traverse_in() const;
    bool               search(T) const; 
    void                     insert(T); 
    void                      erase(T); /////------

private: // helpers
    void      level_order_traversal_i(node*) const;
    void              traverse_post_r(node*) const;
    void               traverse_pre_r(node*) const; 
    void                traverse_in_r(node*) const;
    node*                 predecessor(node*) const;
    node*                   successor(node*) const; 
    node*                   get_max_r(node*) const;
    node*                   get_min_r(node*) const; 
    bool                  search_r(node*, T) const; 
    void                              insert_rb(T); 
    void                       right_rotate(node*); 
    void                        left_rotate(node*);  
    void                       insert_fixup(node*);                    
    node*                        erase_r(node*, T);   // -----

private:
    node* _root;
    static inline node* _nil = new node;
};

#include "rb.tpp"
#endif //RB
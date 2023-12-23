template<typename T>
rb<T>::rb()
    : _root{new node}
{
    _nil->_color = color::black;
    _root->_praent = _nil;
}

template<typename T>
rb<T>::node::node()
    :           _praent{} 
    ,             _left{}
    ,            _right{}
    ,              _val{}
    ,  _color{color::red}
{
}

template<typename T>
rb<T>::node::node(T v)
    :      _praent{_nil} 
    ,        _left{_nil}
    ,       _right{_nil}
    ,            _val{v}
    , _color{color::red}
    
{
}

template<typename T>
void rb<T>::insert(T v)
{
    _root = insert_r(_root, v);
}

template<typename T>
void rb<T>::erase(T v)
{
    _root = erase_r(_root, v);
}

template<typename T>
bool rb<T>::search(T v) const
{
    return search_r(v);
}

template<typename T>
void rb<T>::traverse_pre() const
{
    traverse_pre_r(_root);
}

template<typename T>
void rb<T>::traverse_in() const
{
    traverse_in_r(_root); 
}

template<typename T>
void rb<T>::traverse_post() const
{
    traverse_post_r(_root);
}


    // ----------------------------------------------------------------------//
   //-----------------------------------------------------------------------//
  //--------------------------- helpers------------------------------------//
 //-----------------------------------------------------------------------//
//-----------------------------------------------------------------------//

template<typename T>
bool rb<T>::search_r(node* curr, T v) const      ////////////////////////
{
}

template<typename T>
typename rb<T>::node* rb<T>::insert_r(node* curr, T v) ///////////// ------------
{
    
}

template<typename T>
typename rb<T>::node* rb<T>::erase_r(node* root, T v)    /////////---------
{
    
} 

template<typename T>
typename rb<T>::node*rb<T>::left_rotate(node* root) ////////////////
{
    node* y = root->_right;
    root->_right = y->_left;

    if (y->_left != _nil)
    {
        y->_left->_parent = root;
    }

    y->_parent = root->_parent;

    if (root->_parent == _nil)
    {
        _root = y;
    }
    else if (root == root->_parent->_left)
    {
        root->_praent->_left = y;
    }
    else
    {
        root->_praent->_right = y;
    }

    y->_left = root;
    root->_praent = y;
    return y;
}

template<typename T>
typename rb<T>::node* rb<T>::right_rotate(node* root) /////////////
{
    node* y = root->left;
    root->_left = y->_right;

    if (y->_right != _nil)
    {
        y->_right->_parent = root;
    }

    y->_praent = root->_praent;

    if (root->_praent == _nil)
    {
        _root = y;
    }
    else if(root == root->_praent->_left)
    {
        root->_praent->_left = y;
    }
    else
    {
        root->_praent->_right = y;
    }

    y->_right = root;
    root->_praent = y;
    return y;
}

template<typename T>
typename rb<T>::node* rb<T>::predecessor(node* curr) const
{
    if (!curr) return nullptr;
    if (curr->_left) return get_max_r(curr->_left);

    node* pred = nullptr;
    node* ancestor = _root;
    while (curr != ancestor)
    {
        if (curr->_val > ancestor->_val)
        {
            pred = ancestor;
            ancestor = ancestor->_right;
        }
        else
        {
            ancestor = ancestor->_left;
        }
    }
    return pred;
}

template<typename T>
typename rb<T>::node* rb<T>::successor(node* curr) const
{
    if (!curr) return nullptr;
    if (curr->_right) return get_min_r(curr->_right);

    node* ancestor = _root;
    node* success = nullptr;

    while (ancestor != curr)
    {
        if (ancestor->_val > curr->_val)
        {
            success = ancestor;
            ancestor = ancestor->_left;
        }
        else
        {
            ancestor = ancestor->_right;
        }
    }
    return success;
}

template<typename T>
typename rb<T>::node* rb<T>::get_max_r(node* curr) const
{
    if (!curr) return nullptr;
    if (!curr->_right) return curr;
    return get_max_r(curr->_right);
}

template<typename T>
typename rb<T>::node* rb<T>::get_min_r(node* curr) const
{
    if (!curr) return nullptr;
    if (!curr->_left) return curr;
    return get_min_r(curr->_left);
}

template<typename T>
void rb<T>::traverse_pre_r(node* node) const
{
    if (!node) return;
    std::cout << node->_val << " ";
    traverse_pre_r(node->_left);
    traverse_pre_r(node->_right);
    
}

template<typename T>
void rb<T>::traverse_in_r(node* node) const
{
    if (!node) return;
    traverse_in_r(node->_left);
    std::cout << node->_val << " ";
    traverse_in_r(node->_right);
    
}

template<typename T>
void rb<T>::traverse_post_r(node* node) const
{
    if (!node) return;
    traverse_post_r(node->_left);
    traverse_post_r(node->_right);
    std::cout << node->_val << " ";
}






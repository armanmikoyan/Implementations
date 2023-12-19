template<typename T>
bst<T>::bst()
    : _root{}
{
}

template<typename T>
bst<T>::node::node()
    :  _left{}
    , _right{}
    ,   _val{}
{
}

template<typename T>
bst<T>::node::node(T v)
    :  _left{}
    , _right{}
    ,  _val{v}
{
}

template<typename T>
void bst<T>::insert(T v)
{
    _root = insert_r(_root, v);
}

template<typename T>
void bst<T>::erase(T v)
{
    _root = erase_r(_root, v);
}

template<typename T>
bool bst<T>::search(T v) const
{
    return search_i(v);
}

template<typename T>
void bst<T>::traverse_pre() const
{
    traverse_pre_r(_root);
}

template<typename T>
void bst<T>::traverse_in() const
{
 // traverse_in_r(_root); // recursive
    traverse_in_i();
}

template<typename T>
void bst<T>::traverse_post() const
{
    traverse_post_r(_root);
}

template<typename T>
void bst<T>::level_order_traversal() const
{
     level_order_traversal_i(); // iterative
    // for (int i = 0; i <= depth_r(_root); ++i)
    // {
    //     level_order_traversal_r(_root, i); // recursive
    // }
}




// ---------------------------------------------------------------------//
//----------------------------------------------------------------------//
//-------------------iterative impementations---------------------------//
//----------------------------------------------------------------------//
//----------------------------------------------------------------------//
template<typename T>
void bst<T>::insert_i(T v)
{
    node* new_node = new node(v);

    if (!_root)
    {
        _root = new_node;
    }
    else
    {
        node* curr = _root;
        node* parent = nullptr;
        while (curr)
        {
            parent = curr;
            if (curr->_val > v)
            {
             
                curr = curr->_left;
            }
            else
            {
                curr = curr->_right;
            }
        }
        if (parent->_val > v)
        {
            parent->_left = new_node;
        }
        else
        {
            parent->_right = new_node;
        }
    }
}

template<typename T>
bool bst<T>::search_i(T v) const
{
    node* curr = _root;
    while (curr)
    {
        if (curr->_val == v) return true;
        else if (curr->_val > v)
        {
            curr = curr->_left;
        }
        else
        {
            curr = curr->_right;
        }
    }
    return false;
}

template<typename T>
typename bst<T>::node* bst<T>::get_max_i(node* curr) const
{
    if (!curr) return nullptr;
    if (!curr->_right) return curr;
    while (curr->_right)
    {
        curr = curr->_right;
    }
    return curr;
}

template<typename T>
typename bst<T>::node* bst<T>::get_min_i(node* curr) const
{
    if (!curr) return nullptr;
    if (!curr->_left) return curr;
    while (curr->_left)
    {
        curr = curr->_left;
    }
    return curr;
}

template<typename T>
void bst<T>::level_order_traversal_i() const
{   
    node* curr = _root;
    if (!curr) return;
    std::queue<node*> queue;
    queue.push(_root);
    while (!queue.empty())
    {
        int sz = queue.size();
        while (sz--)
        {
            node* top =  queue.front();
            queue.pop();
            std::cout << top->_val << " ";
            if (top->_left)
            {
                queue.push(top->_left);
            }
            if (top->_right)
            {
                queue.push(top->_right);
            }   
        }  
    }
}

template<typename T>
typename bst<T>::node* bst<T>::predecessor(node* curr) const
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
typename bst<T>::node* bst<T>::successor(node* curr) const
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

// template<typename T>
// int bst<T>::depth_i() const
// {
//     if (!root) return -1;
//     node *curr = _root;
//     int max = 0;

// }
// template<typename T>
// void bst<T>::traverse_post_i() const
// {

// }                                                                 /// pti arvi sranq

// template<typename T>
// void bst<T>::traverse_pre_i() const                  
// { 
    
// }

template<typename T>
void bst<T>::traverse_in_i() const
{
    if(!_root) return;
    node* curr = _root;
    std::stack<node*> stack;
    while (curr || !stack.empty())
    {
        while (curr)
        {
            stack.push(curr);
            curr = curr->_left;                  // --------------
        }
        curr = stack.top();
        stack.pop();

        std::cout << curr->_val << " ";

        curr = curr->_right;
    }
}



// ---------------------------------------------------------------------//
//----------------------------------------------------------------------//
//-------------------recursive impementations---------------------------//
//----------------------------------------------------------------------//
//----------------------------------------------------------------------//
template<typename T>
typename bst<T>::node* bst<T>::insert_r(node* curr, T v)
{
    if (!curr) return new node(v);
    else if (curr->_val > v)
    {
        curr->_left = insert_r(curr->_left, v);
    }
    else 
    {
        curr->_right = insert_r(curr->_right, v);
    }
    return curr;
}

template<typename T>
bool bst<T>::search_r(node* curr, T v) const
{
    if (!curr) return false;

    if (curr->_val == v) return true;

    else if (curr->_val > v)
    {
        return search_r(curr->_left, v);
    }
    else
    {
        return search_r(curr->_right, v);
    }
}

template<typename T>
typename bst<T>::node* bst<T>::erase_r(node* root, T v)
{
    if (!root) return root;
    
    if (root->_val > v)
    {
        root->_left = erase_r(root->_left, v);
    }
    else if (root->_val < v)
    {
        root->_right = erase_r(root->_right, v);
    }
    else
    {
        if (!root->_left && !root->_right) 
        {
            delete root;
            return  nullptr;
        }
        else if (!root->_left && root->_right || root->_left && !root->_right)
        {
            if (!root->_right)
            {
                node* tmp = root->_left;
                delete root;
                return tmp;
            }
            else
            {
                node* tmp = root->_right;
                delete root;
                return tmp;
            }
        }
        else
        {
            auto tmp = get_max_r(root->_left);
            std::swap(root->_val, tmp->_val);
            root->_left = erase_r(root->_left, tmp->_val);
        }
    }
    return root;
}

template<typename T>
int  bst<T>::depth_r(node* curr) const
{
    if (!curr) return -1;
    int left =   depth_r(curr->_left);
    int right = depth_r(curr->_right);
    return std::max(left, right) + 1;
}

template<typename T>
typename bst<T>::node* bst<T>::get_max_r(node* curr) const
{
    if (!curr) return nullptr;
    if (!curr->_right) return curr;
    return get_max_r(curr->_right);
}

template<typename T>
typename bst<T>::node* bst<T>::get_min_r(node* curr) const
{
    if (!curr) return nullptr;
    if (!curr->_left) return curr;
    return get_min_r(curr->_left);
}

template<typename T>
void bst<T>::traverse_pre_r(node* node) const
{
    if (!node) return;
    std::cout << node->_val << " ";
    traverse_pre_r(node->_left);
    traverse_pre_r(node->_right);
    
}

template<typename T>
void bst<T>::traverse_in_r(node* node) const
{
    if (!node) return;
    traverse_in_r(node->_left);
    std::cout << node->_val << " ";
    traverse_in_r(node->_right);
    
}

template<typename T>
void bst<T>::traverse_post_r(node* node) const
{
    if (!node) return;
    traverse_post_r(node->_left);
    traverse_post_r(node->_right);
    std::cout << node->_val << " ";
}

template<typename T>
void bst<T>::level_order_traversal_r(node* curr, int level) const
{   
    if (!curr) return;
    if (level == 0)
    {
        std::cout << curr->_val << " ";
    }
    if (level > 0)
    {
        level_order_traversal_r(curr->_left, level - 1);
        level_order_traversal_r(curr->_right, level - 1);
    }
}







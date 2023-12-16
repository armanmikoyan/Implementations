template<typename T>
avl<T>::avl()
    : _root{}
{
}

template<typename T>
avl<T>::node::node()
    :  _left{}
    , _right{}
    ,   _val{}
{
}

template<typename T>
avl<T>::node::node(T v)
    :  _left{}
    , _right{}
    ,  _val{v}
{
}

template<typename T>
void avl<T>::insert(T v)
{
    _root = insert_r(_root, v);
}

template<typename T>
void avl<T>::erase(T v)
{
    _root = erase_r(_root, v);
}

template<typename T>
bool avl<T>::search(T v) const
{
    return search_r(v);
}

template<typename T>
void avl<T>::traverse_pre() const
{
    traverse_pre_r(_root);
}

template<typename T>
void avl<T>::traverse_in() const
{
    traverse_in_r(_root); 
}

template<typename T>
void avl<T>::traverse_post() const
{
    traverse_post_r(_root);
}

template<typename T>
void avl<T>::level_order_traversal() const
{
    for (int i = 0; i <= depth_r(_root); ++i)
    {
        level_order_traversal_r(_root, i); 
    }
}



    // ----------------------------------------------------------------------//
   //-----------------------------------------------------------------------//
  //--------------------------- helpers------------------------------------//
 //-----------------------------------------------------------------------//
//-----------------------------------------------------------------------//
template<typename T>
typename avl<T>::node* avl<T>::insert_r(node* curr, T v)
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

    // rotation if needed
    int bf = balance_factor(curr);
     
    if (bf > 1 && curr->_left->_val > v)                  // 1. left subtree is heavy and inserted to the left side
    {
        return right_rotate(curr);                          //  LL CASE
    }

    else if(bf > 1 && curr->_left->_val < v)             //  2. left subtree is heavy and inserted to the right side
    {                                                 
        curr->_left =  left_rotate(curr);                    // LR CASE
        return right_rotate(curr);
    }

    else if (bf < -1 && curr->_right->_val > v)          //  3. right subtree is heavy  and inserted to the left side
    {
        curr->_right = right_rotate(curr->_right);          //  RL CASE
        return left_rotate(curr);
    }

    else if(bf < -1 && curr->_right->_val < v)            // 4. right subtree is heavy  and inserted to the right side
    {
        return left_rotate(curr);                           //  RR CASE
    }

    return curr;   // rotations doesn't happend
}

template<typename T>
bool avl<T>::search_r(node* curr, T v) const
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
typename avl<T>::node* avl<T>::erase_r(node* root, T v)
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
int avl<T>::balance_factor(node* curr) const
{
    if (!curr) return 0;
    return depth_r(curr->_left) - depth_r(curr->_right);
}

template<typename T>
typename avl<T>::node* avl<T>::right_rotate(node* root)
{
    // save left child of root, and right child of  left
    node* y = root->_left;
    node* left_right = y->_right;

    // right rotation
    y->_right = root;
    root->_left = left_right;

    // new root
    return y;
}

template<typename T>
typename avl<T>::node*avl<T>::left_rotate(node* root)
{
    //save right child of root, and left child of right child
    node* y = root->_right;
    node* right_left = y->_left;

    // left rotation
    y->_left = root;
    root->_right = right_left;

    //new root
    return y;
}

template<typename T>
typename avl<T>::node* avl<T>::predecessor(node* curr) const
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
typename avl<T>::node* avl<T>::successor(node* curr) const
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
int  avl<T>::depth_r(node* curr) const
{
    if (!curr) return -1;
    int left =   depth_r(curr->_left);
    int right = depth_r(curr->_right);
    return std::max(left, right) + 1;
}

template<typename T>
typename avl<T>::node* avl<T>::get_max_r(node* curr) const
{
    if (!curr) return nullptr;
    if (!curr->_right) return curr;
    return get_max_r(curr->_right);
}

template<typename T>
typename avl<T>::node* avl<T>::get_min_r(node* curr) const
{
    if (!curr) return nullptr;
    if (!curr->_left) return curr;
    return get_min_r(curr->_left);
}

template<typename T>
void avl<T>::traverse_pre_r(node* node) const
{
    if (!node) return;
    std::cout << node->_val << " ";
    traverse_pre_r(node->_left);
    traverse_pre_r(node->_right);
    
}

template<typename T>
void avl<T>::traverse_in_r(node* node) const
{
    if (!node) return;
    traverse_in_r(node->_left);
    std::cout << node->_val << " ";
    traverse_in_r(node->_right);
    
}

template<typename T>
void avl<T>::traverse_post_r(node* node) const
{
    if (!node) return;
    traverse_post_r(node->_left);
    traverse_post_r(node->_right);
    std::cout << node->_val << " ";
}

template<typename T>
void avl<T>::level_order_traversal_r(node* curr, int level) const
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







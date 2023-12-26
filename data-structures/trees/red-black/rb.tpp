template<typename T>
rb<T>::rb()
    : _root{}
{
    _nil->_color = color::black;
    _root = _nil;
}

template<typename T>
rb<T>::node::node()
    :           _parent{} 
    ,             _left{}
    ,            _right{}
    ,              _val{}
    ,  _color{color::red}
{
}

template<typename T>
rb<T>::node::node(T v)
    :      _parent{_nil} 
    ,        _left{_nil}
    ,       _right{_nil}
    ,            _val{v}
    , _color{color::red}
    
{
}

template<typename T>
void rb<T>::insert(T v)
{
    insert_rb(v);
}

template<typename T>
void rb<T>::erase(T v)
{
    _root = erase_r(_root, v);
}

template<typename T>
bool rb<T>::search(T v) const
{
    return search_r(_root, v);
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


template<typename T>
void rb<T>::level_order_traversal() const
{
    level_order_traversal_i(_root);
}





    // ----------------------------------------------------------------------//
   //-----------------------------------------------------------------------//
  //--------------------------- helpers------------------------------------//
 //-----------------------------------------------------------------------//
//-----------------------------------------------------------------------//

template<typename T>
bool rb<T>::search_r(node* curr, T v) const    
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
void rb<T>::insert_rb(T v)  
{
    node* z = new node(v);
    node *x = _root;
    node *parent = _nil;

    while (x != _nil)
    {
        parent = x;
        if (z->_val > x->_val)
        {
            x = x->_right;
        }
        else
        {
            x = x->_left;
        }
    }
    z->_parent = parent;
    if (parent == _nil)
    {
        _root = z;
    }
    else if (z->_val > parent->_val)
    {
        parent->_right = z;
    }
    else
    {
        parent->_left = z;
    }

    insert_fixup(z);
}

template<typename T>
void rb<T>::insert_fixup(node* z)
{
   while (z->_parent->_color == color::red)
   {
       if (z->_parent == z->_parent->_parent->_left) // left mirror case: z's parent is a left child of z's grandparent
       {
           node* uncle = z->_parent->_parent->_right;
           if (uncle->_color == color::red) // CASE 1: uncle is red;              
           {
               z->_parent->_parent->_color = color::red;
               z->_parent->_color = color::black;
               uncle->_color = color::black;
               z = z->_parent->_parent;
           }
           else // CASE: 2 uncle is black
           {
               if (z == z->_parent->_right) // intermediate case lr case,  for going 3 case
               {
                   z = z->_parent;                    
                   left_rotate(z);                           
               }
               z->_parent->_color = color::black;            //
               z->_parent->_parent->_color = color::red;    //  case 3
               right_rotate(z->_parent->_parent);          //
           }
       }


       else // right mirror case: z's parent is a right child of z's grandparent
       {
            node* uncle = z->_parent->_parent->_left;
            if (uncle->_color == color::red) // CASE 1: uncle is red
            {
                z->_parent->_parent->_color = color::red;    
                z->_parent->_color = color::black;
                uncle->_color = color::black;
                z = z->_parent->_parent;
            }
            else // CASE 2: uncle color is black
            {
                if (z == z->_parent->_left) // intermediate case rl case,  for going 3 case
                {
                    z = z->_parent;
                    right_rotate(z);   
                }
                z->_parent->_color = color::black;          //
                z->_parent->_parent->_color = color::red;  //    case 3  
                left_rotate(z->_parent->_parent);         //
            }
       }
   }

   _root->_color = color::black;
}

template<typename T>
typename rb<T>::node* rb<T>::erase_r(node* root, T v)    /////////---------
{
    
} 

template<typename T>
void rb<T>::left_rotate(node* root) 
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
        root->_parent->_left = y;
    }
    else
    {
        root->_parent->_right = y;
    }

    y->_left = root;
    root->_parent = y;
}

template<typename T>
void rb<T>::right_rotate(node* root)
{
    node* y = root->_left;
    root->_left = y->_right;

    if (y->_right != _nil)
    {
        y->_right->_parent = root;
    }

    y->_parent = root->_parent;

    if (root->_parent == _nil)
    {
        _root = y;
    }
    else if(root == root->_parent->_left)
    {
        root->_parent->_left = y;
    }
    else
    {
        root->_parent->_right = y;
    }

    y->_right = root;
    root->_parent = y;
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
    if (node->_val)
    {
        std::cout << node->_val << " ";
    }
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

template<typename T>
void rb<T>::level_order_traversal_i(node* root) const
{   
    node* curr = root;
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
            if (top != _nil)
            {
                if((int(top->_color)))
                {
                   std::cout << "\033[1;30m";
                }
                else
                {
                    std::cout << "\033[31m"; 
                }
                std::cout << top->_val << " ";
                std::cout << "\033[0m";
            }

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
    std::cout << std::endl;
}

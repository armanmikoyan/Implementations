template<typename T>
soll<T>::soll::Node::Node()
    : _data{}
    , _next{}
    , _prev{}
    , _asc{}
    , _desc{}
{
}

template<typename T>
soll<T>::soll::Node::Node(const T& val)
    : _data{val}
    , _next{}
    , _prev{}
    , _asc{} 
    , _desc{}
{
}

template<typename T>
soll<T>::soll()
    :      _head{}
    ,      _tail{}
    ,  _asc_head{}
    , _desc_head{}
{
}

template<typename T>
soll<T>::~soll()
{
    Node* curr = _head;
    while (curr)
    {
        Node* tmp = curr->_next;
        delete curr;
        curr = tmp;
    }
    _head = nullptr;    
}

template<typename T>
soll<T>::soll(const soll& oth)
    : _head{}
    , _tail{}
    , _asc_head{}
    , _desc_head{}
{    
    Node* curr = oth._head;
    while (curr) 
    {
        push_back(curr->_data);
        curr = curr->_next;
    }  
}

template<typename T>
soll<T>::soll(soll&& oth) noexcept 
    : _head(oth._head)
    , _tail(oth._tail) 
    , _asc_head{oth._asc_head}
    , _desc_head{oth._desc_head}
{
    oth._head = nullptr;
    oth._tail = nullptr;
    oth._asc_head = nullptr;
    oth._desc_head = nullptr;
}

template<typename T>
soll<T>& soll<T>::operator=(const soll& oth) 
{
    if (this != &oth) 
    {
        while (_head) 
        {
            Node* temp = _head;
            _head = _head->_next;
            delete temp;
        }
        _head = nullptr;

        Node* othcurr = oth._head;
        while (othcurr) 
        {
            push_back(othcurr->_data);
            othcurr = othcurr->_next;
        }
    }
    return *this;
}


template<typename T>
soll<T>& soll<T>::operator=(soll<T>&& oth) noexcept 
{
    if (this != &oth) 
    {
        while (_head) 
        {
            Node* temp =   _head;
            _head = _head->_next;
            delete          temp;
        }
        _head =           oth._head;
        _tail =           oth._tail;
        _asc_head =   oth._asc_head;
        _desc_head = oth._desc_head;

        oth._head =      nullptr;
        oth._tail =      nullptr;
        oth._asc_head =  nullptr;
        oth._desc_head = nullptr;
    }
    return *this;
}


template<typename T>
void soll<T>::push_back(const T& val)
{
    Node* new_node = new Node{val};
    if (!_head)
    {
        _head =      new_node;
        _tail =      new_node;
        _asc_head =  new_node;
        _desc_head = new_node;
        return;
    }

    _tail->_next = new_node;
    new_node->_prev = _tail;
    _tail =        new_node;
    asc_desc_new_node(new_node);
}

template<typename T>
void soll<T>::push_front(const T& val)
{
    if (!_head)
    {
        push_back(val);
        return;
    }
    Node* new_node = new Node{val};
    _head->_prev = new_node;
    new_node->_next = _head;
    _head = new_node;
    asc_desc_new_node(new_node);
}

template<typename T>
void soll<T>::pop_back()
{
    if (!_head) return;

    else if (!_head->_next)
    {
        delete _head;
        _head =      nullptr;
        _tail =      nullptr;
        _asc_head =  nullptr;
        _desc_head = nullptr;
    }
    else
    {
        asc_desc_exsist_node(_tail);
        _tail->_prev->_next = nullptr;
        Node* tmp = _tail->_prev;
        delete _tail;
        _tail = tmp;
    }
}

template<typename T>
void soll<T>::pop_front()
{
    if (!_head || !_head->_next)
    {
       pop_back();
       return; 
    }
    asc_desc_exsist_node(_head);
    _head->_next->_prev = nullptr;
    Node* tmp = _head->_next;
    delete _head;
    _head = tmp;
    
}

template<typename T>
void soll<T>::asc_desc_new_node(Node* new_node)
{
   if (new_node->_data >= _desc_head->_data)
   {
       _desc_head->_asc = new_node;
       new_node->_desc = _desc_head;
       _desc_head = new_node;
   }
   else if (new_node->_data <= _asc_head->_data)
   {
       _asc_head->_desc = new_node;
       new_node->_asc = _asc_head;
       _asc_head = new_node;
   }
   else
   {
        Node* tmp = _asc_head;
        while (tmp->_data < new_node->_data)
        {
            tmp = tmp->_asc;
        }

        tmp->_desc->_asc = new_node;
        new_node->_desc = tmp->_desc;
        new_node->_asc = tmp;
        tmp->_desc = new_node;
   }
}

template<typename T>
void soll<T>::insert(size_t idx, const T& val)
{
    if (idx == 0)
    {
        push_front(val);
        return;
    }

    Node* curr = _head;
    while (curr && idx)
    {
        curr = curr->_next;
        idx--;
    }
    if (idx == 0 && !curr)
    {
        push_back(val);
        return;
    }

    if (!curr)
    {
        throw std::out_of_range("position is greater or smaller");
    }

    Node* new_node = new Node(val);
    curr->_prev->_next = new_node;
    new_node->_prev = curr->_prev;
    curr->_prev = new_node;
    new_node->_next = curr;
    asc_desc_new_node(new_node); 
}

template<typename T>
void soll<T>::erase(size_t idx)
{
    if (idx == 0)
    {
        pop_front();
        return;
    }

    Node* curr = _head;
    while (curr && idx)
    {
        --idx;
        curr = curr->_next;
    }
    if (!curr &&  idx > 0)
    {
        throw std::out_of_range("position is greater or smaller");
    }
    if (_tail == curr)
    {
        pop_back();
        return;
    }
    else
    {
        asc_desc_exsist_node(curr);
        curr->_next->_prev = curr->_prev;
        curr->_prev->_next = curr->_next;
        delete curr;
    }
  
}

template<typename T>
void soll<T>::promote(Node* node)
{
    if (node == _head) return;

    if (node == _tail)
    {
        _tail = node->_prev;
        node->_prev->_next = nullptr;
        node->_prev = _tail->_prev;
        _tail->_prev->_next = node;
        node->_next = _tail;
        _tail->_prev = node;
    }
    else if (node->_prev == _head)
    {
        _head = node;
        node->_prev->_next = node->_next;
        node->_next->_prev = node->_prev;
        node->_prev->_prev = node;
        node->_next = node->_prev;
        node->_prev = nullptr;
    }
    else
    {
        Node* tmp = node->_prev->_prev;
        node->_next->_prev = node->_prev;
        node->_prev->_next = node->_next;
        node->_prev->_prev = node;
        node->_next = node->_prev;
        node->_prev = tmp;
        tmp->_next = node;
    }
}

template<typename T>
bool soll<T>::search(const T& val)
{
    Node* curr = _head;
    while (curr)
    {
        if (curr->_data == val)
        {
            promote(curr);
            return true;
        }
        curr = curr->_next;
    }
    return false;
}

template<typename T>
void soll<T>::asc_desc_exsist_node(Node* node)
{
    if (_asc_head == node)
    {
        _asc_head->_asc->_desc = nullptr;
        _asc_head = _asc_head->_asc;
    }
    else if (_desc_head == node)
    {
        _desc_head->_desc->_asc = nullptr;
        _desc_head = _desc_head->_desc;
    }
    else
    {
        node->_asc->_desc = node->_desc;
        node->_desc->_asc = node->_asc;
    }
}

template<typename T>
void soll<T>::traverse()
{
    Node* head_tmp =  _head;
    std::cout << "normal\n";
    while (head_tmp)
    {
        std::cout << head_tmp->_data << " -> ";
        head_tmp = head_tmp->_next;
    }
    std::cout << std::endl;
    std::cout << std::endl;
    

    Node* tail_tmp = _tail;
    std::cout << "reverse\n";
    while (tail_tmp)
    {
        std::cout << tail_tmp->_data << " <- ";
        tail_tmp = tail_tmp->_prev;
    }
    std::cout << std::endl;
    std::cout << std::endl;


    Node* asc_tmp = _asc_head;
    std::cout << "asc\n";
    while (asc_tmp)
    {
        std::cout << asc_tmp->_data << " -> ";
        asc_tmp = asc_tmp->_asc;
    }
    std::cout << std::endl;
    std::cout << std::endl;


    Node* desc_tmp = _desc_head;
    std::cout << "desc\n";
    while (desc_tmp)
    {
        std::cout << desc_tmp->_data << " -> ";
        desc_tmp = desc_tmp->_desc;
    }
    std::cout << std::endl;
}
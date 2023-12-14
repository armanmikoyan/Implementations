template<typename T>
dll<T>::Node::Node(const T& data)
    : _data{data}
    , _next{}
    , _prev{}
{
}

template<typename T>
dll<T>::dll()
    : _head{}
    , _tail{}
{
}

template<typename T>
dll<T>::dll(const dll<T>& oth)
    : _head{nullptr}
    , _tail{nullptr}
{

    Node* othcurr = oth._head;
    while (othcurr) 
    {
        push_back(othcurr->_data);
        othcurr = othcurr->_next;
    }
}

template<typename T>
dll<T>::dll(dll<T>&& oth) noexcept 
    : _head(oth._head)
    , _tail(oth._tail) 
{
    oth._head = nullptr;
    oth._tail = nullptr;
}

template<typename T>
dll<T>& dll<T>::operator=(const dll<T>& oth) 
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
dll<T>& dll<T>::operator=(dll<T>&& oth) noexcept 
{
    if (this != &oth) 
    {
        while (_head) 
        {
            Node* temp = _head;
            _head = _head->_next;
            delete temp;
        }
        _head = oth._head;
        _tail = oth._tail;

        oth._head = nullptr;
        oth._tail = nullptr;
    }
    return *this;
}

template<typename T>
dll<T>::~dll()
{
    Node* curr = _head;
    Node* tmp;
    while (curr)
    {
        tmp = curr->_next;
        delete curr;
        curr = tmp;
    }
}

template<typename T>
void dll<T>::push_front(const T& val)
{
    Node* new_node = new Node(val);
    if (!_head) 
    {
        _head = new_node;
        _tail = new_node;
        return;
    }
    else
    {
        new_node->_next = _head;
        new_node->_next->_prev = new_node;
        _head = new_node;

    }
}

template<typename T>
void dll<T>::push_back(const T& val)
{
    Node* new_node = new Node(val);
    if (!_tail) 
    {
        _head = new_node;
        _tail = new_node;
        return;
    }
    else
    {
        new_node->_prev = _tail;
        new_node->_prev->_next = new_node;
        _tail = new_node;

    }
}

template<typename T>
void dll<T>::pop_back()
{
    if (_tail)
    {
        if (_head == _tail)
        {
            delete _head;
            _tail = nullptr;
            _head = nullptr;

        }
        else
        {
            Node* tmp = _tail->_prev;
            _tail->_prev->_next = nullptr;
            delete _tail;
            _tail = tmp;
        }
    }
}

template<typename T>
void dll<T>::pop_front()
{
    if (_head)
    {
        if (_head == _tail)
        {
            delete _head;
            _tail = nullptr;
            _head = nullptr;
        }
        else
        {
            Node* tmp = _head->_next;
            _head->_next->_prev = nullptr;
            _head = tmp;
        }
    }
}


template<typename T>
bool dll<T>::search(const T& val)
{
    Node* tmp = _head;
    while (tmp)
    {
        if (tmp->_data == val) return 1;
        tmp = tmp->_next;
    }
    return 0;
}

template<typename T>
void dll<T>::insert(size_t idx, const T& val)
{
    if (idx == 0) 
    {
        push_front(val);
        return;
    }

    Node* tmp = _head;
    int size{};
    while (tmp)
    {
        ++size;
        tmp = tmp->_next;
    }
    if (idx > size)
    {
        throw std::out_of_range("range error");
    }
    if (idx == size)
    {
        push_back(val);
        return;
    }

    Node* curr = _head;
    Node* new_node = new Node(val);
    while (curr && idx)
    {
        idx--;
        curr = curr->_next;
    }
    curr->_prev->_next = new_node;
    new_node->_prev = curr->_prev;
    curr->_prev = new_node;
    new_node->_next = curr;
}


template<typename T>
void dll<T>::erase(size_t pos)
{
    if (pos == 0)
    {
        pop_front();
    }

    Node* curr = _head;
    while (pos)
    {
        --pos;
        curr = curr->_next;
    }
    Node* tmp = curr;
    curr->_next->_prev = curr->_prev;
    curr->_prev->_next = curr->_next;
    delete tmp;
}

template<typename T>
void dll<T>::reverse()
{
    if (!(_head && _head->_next)) return;
    Node* prev = nullptr;
    Node* curr  = _head;
    Node* next = curr->_next;

    while (curr)
    {
        next = curr->_next;

        curr->_next = prev;
        curr->_prev = next;
        prev = curr;
        curr = next; 
    }
    _tail = _head;
    _head = prev;
}

template<typename T>
typename dll<T>::Node* dll<T>::mid()
{
     if (!_head) return nullptr;

     Node* slow = _head;
     Node* fast = _head;
     while (fast->_next && fast->_next->_next)
     {
          fast = fast->_next->_next;
          slow = slow->_next;
     }
     return slow;
}


template<typename T>
void dll<T>::traverse()
{   
    Node* tmp = _head;
    while (tmp)
    {
        std::cout << tmp->_data << "-->";
        tmp = tmp->_next;
    }
    std::cout << "\n";
    std::cout << "\n";
    Node* tmp_2 = _tail;
    while (tmp_2)
    {
        std::cout << tmp_2->_data << "-->";
        tmp_2 = tmp_2->_prev;
    }
    std::cout << "\n";
}

  

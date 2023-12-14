template<typename T>
list<T>::Node::Node(const T& data)
     : _data{data}
     , _next{nullptr}
{
}

template<typename T>
list<T>::list()
     : _head{nullptr}
{
}

template<typename T>
list<T>::list(const list<T>& oth) 
     : _head(nullptr) 
{
    Node* othcurr = oth._head;
    while (othcurr) 
    {
        push_back(othcurr->_data);
        othcurr = othcurr->_next;
    }
}

template<typename T>
list<T>::list(list<T>&& oth) noexcept 
     : _head(oth._head) 
{
    oth._head = nullptr;
}

template<typename T>
list<T>& list<T>::operator=(const list<T>& oth) {
   
    if (this != &oth) 
    {

        while (_head) 
        {
          Node* temp = _head;
          _head = _head->_next;
          delete temp;
        }
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
list<T>& list<T>::operator=(list<T>&& oth) noexcept {
  
    if (this != &oth) 
    {
        while (_head) 
        {
            Node* temp = _head;
            _head = _head->_next;
            delete temp;
        }
        _head = oth._head;
        oth._head = nullptr;
    }
    return *this;
}

template<typename T>
list<T>::~list()
{
     Node* tmp = _head;
     Node* curr = tmp;
     while(tmp)
     {
          curr = tmp->_next;
          delete tmp;
          tmp = curr;
     }
}

template<typename T>
void list<T>::push_back(const T& val)
{
     Node* new_node = new Node(val);
     if (!_head)
     {
          _head = new_node;
          return;
     }

     Node* curr = _head;
     while (curr->_next)
     {
          curr = curr->_next;
     }

     curr->_next = new_node;
}

template<typename T>
void list<T>::push_front(const T& val)
{
     Node* new_node = new Node(val);
     if (!_head)
     {
          _head = new_node;
          return;
     }

     new_node->_next = _head;
     _head = new_node;
}

template<typename T>
void list<T>::pop_front()
{
     if (!_head) return;

     delete _head;
     _head = _head->_next;
}

template<typename T>
void list<T>::pop_back()
{
     if (!_head) return;

     if (!_head->_next)
     {
          delete _head;
          _head = nullptr;
          return;
     }

     Node* tmp = _head;

     while (tmp->_next->_next)
     {
          tmp = tmp->_next;
     }
     
     delete tmp->_next;
     tmp->_next = nullptr;
}

template<typename T>
bool list<T>::search(const T& val)
{
     Node* curr = _head;

     while (curr)
     {
          if (curr->_data == val)
          {
               return true;
          }
          curr = curr->_next;
     }

     return false;
}


template<typename T>
void list<T>::insert(size_t idx, const T& val)
{
     if (idx == 0)
     {
          push_front(val);
          return;
     }

     int size{};
     Node* tmp = _head;
     while (tmp)
     {
          ++size;
          tmp = tmp->_next;
     }
     
     if (size == idx)
     {
          push_back(val);
          return;
     }

     Node* curr = _head;
     Node* new_node = new Node(val);
     while (curr && idx - 1)
     {
          idx--;
          curr = curr->_next;
     }
     new_node->_next = curr->_next;
     curr->_next = new_node;
}

template<typename T>
void list<T>::erase(size_t pos)
{
     Node* curr = _head;
     if (pos == 0)
     {
          pop_front();
          return;
     }
     while (pos - 1)
     {
          curr = curr->_next;
          pos--;
     }
     if (!curr->_next)
     {
          pop_back();
     }
     else
     {
          Node* tmp = curr->_next->_next;
          delete curr->_next;   
          curr->_next = tmp;
     }
}

template<typename T>
void list<T>::reverse()
{
     if (!(_head && _head->_next)) return;

     Node* curr = _head;
     Node* prev = nullptr;
     Node* next = _head->_next;

     while (curr)
     {
          next = curr->_next;
          curr->_next = prev;
          prev = curr;
          curr = next;
     }
     _head = prev;
}

template<typename T>
typename list<T>::Node* list<T>::mid()
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
void list<T>::traverse()
{
     Node* curr = _head;
     while (curr)
     {
          std::cout << curr->_data << "-->";
          curr = curr->_next;
     }
     std::cout << std::endl;
}


template<typename T>
typename list<T>::const_iterator list<T>::cbegin()
{
     return const_iterator(_head);
}

template<typename T>
typename list<T>::const_iterator list<T>::cend()
{
     Node* tmp = _head;
     while(tmp)
     {
          tmp = tmp->_next;
     }
     return const_iterator(tmp);
}

template<typename T>
typename list<T>::iterator list<T>::begin()
{
     return iterator(_head);
}

template<typename T>
typename list<T>::iterator list<T>::end()
{
     Node* tmp = _head;
     while(tmp)
     {
          tmp = tmp->_next;
     }
     return iterator(tmp);
}

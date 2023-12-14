//const iterator

template<typename T>
list<T>::const_iterator::const_iterator(list<T>::Node* node)
    : _current{node}
{
}

template<typename T>
typename list<T>::const_reference list<T>::const_iterator::operator*() const
{
    return _current->_data; 
}

template<typename T>
typename list<T>::const_iterator& list<T>::const_iterator::operator++()
{
    _current = _current->_next;
    return *this;
}

template<typename T>
typename list<T>::const_iterator list<T>::const_iterator::operator++(int)
{
    const_iterator tmp(*this);
    ++(*this);
    return tmp;
}

template<typename T>
typename list<T>::const_iterator list<T>::const_iterator::operator+(int count)
{
    const_iterator tmp(*this);
    while (count)
    {
        tmp._current = tmp._current->_next;
        --count;
    }
    return tmp;
}

template<typename T>
bool list<T>::const_iterator::operator==(const const_iterator& rhs) const
{
    return _current == rhs._current;
}

template<typename T>
bool list<T>::const_iterator::operator!=(const const_iterator& rhs) const
{
    return _current != rhs._current;
}


//iterator

template<typename T>
list<T>::iterator::iterator(list<T>::Node* node)
    : _current{node}
{
}

template<typename T>
typename list<T>::reference list<T>::iterator::operator*() const
{
    return _current->_data; 
}

template<typename T>
typename list<T>::iterator& list<T>::iterator::operator++()
{
    _current = _current->_next;
    return *this;
}

template<typename T>
typename list<T>::iterator list<T>::iterator::operator++(int)
{
    iterator tmp(*this);
    ++(*this);
    return tmp;
}

template<typename T>
typename list<T>::iterator list<T>::iterator::operator+(int count)
{
    iterator tmp(*this);
    while (count)
    {
        tmp._current = tmp._current->_next;
        --count;
    }
    return tmp;
}

template<typename T>
bool list<T>::iterator::operator==(const iterator& rhs) const
{
    return _current == rhs._current;
}

template<typename T>
bool list<T>::iterator::operator!=(const iterator& rhs) const
{
    return _current != rhs._current;
}
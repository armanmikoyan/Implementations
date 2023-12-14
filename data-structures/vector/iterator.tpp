template<typename T>
vector<T>::iterator::iterator(T* ptr)
     :    _current(ptr)
{
}

template<typename T>
typename vector<T>::reference vector<T>::iterator::operator*() const
{
     return *_current;
}

template<typename T>
typename vector<T>::iterator& vector<T>::iterator::operator++()
{
     ++_current;
     return *this;
}

template<typename T>
typename vector<T>::iterator vector<T>::iterator::operator++(int)
{
     iterator tmp = *this;
     ++_current;
     return tmp;
}

template<typename T>
typename vector<T>::iterator vector<T>::iterator::operator+(int n)
{
     _current += n;
     return *this;
}

template<typename T>
typename vector<T>::iterator& vector<T>::iterator::operator--()
{
     --_current;
     return *this;
}

template<typename T>
typename vector<T>::iterator vector<T>::iterator::operator--(int)
{
     iterator tmp = *this;
     --_current;
     return tmp;
}

template<typename T>
bool  vector<T>::iterator::operator==(const iterator& oth) const
{
     return _current == oth._current;
}

template<typename T>
bool  vector<T>::iterator::operator!=(const iterator& oth) const
{
     return _current != oth._current;
}



// const iterator

template<typename T>
vector<T>::const_iterator::const_iterator(const T* ptr)
     :    _current(ptr)
{
}

template<typename T>
typename vector<T>::const_reference vector<T>::const_iterator::operator*() const
{
     return *_current;
}

template<typename T>
typename vector<T>::const_iterator& vector<T>::const_iterator::operator++()
{
     ++_current;
     return *this;
}

template<typename T>
typename vector<T>::const_iterator vector<T>::const_iterator::operator++(int)
{
     iterator tmp = *this;
     ++_current;
     return tmp;
}

template<typename T>
typename vector<T>::const_iterator vector<T>::const_iterator::operator+(int n)
{
     _current += n;
     return *this;
}

template<typename T>
typename vector<T>::const_iterator& vector<T>::const_iterator::operator--()
{
     --_current;
     return *this;
}

template<typename T>
typename vector<T>::const_iterator vector<T>::const_iterator::operator--(int)
{
     const_iterator tmp = *this;
     --_current;
     return tmp;
}

template<typename T>
bool  vector<T>::const_iterator::operator==(const const_iterator& oth) const
{
     return _current == oth._current;
}

template<typename T>
bool  vector<T>::const_iterator::operator!=(const const_iterator& oth) const
{
     return _current != oth._current;
}

template<typename T>
stack<T>::stack()
     : _top{-1}
{}

template<typename T>
stack<T>::stack(const stack& oth)
     : _top{oth._top}
     , _data{oth._data}
{}

template<typename T>
stack<T>::stack(stack&& oth) noexcept
     : _top{oth._top}
     , _data{std::move(oth._data)}
{
     oth._top = -1;
}

template<typename T>
stack<T>& stack<T>::operator=(stack&& oth) noexcept
{
     if (this != &oth)
     {
          _top = oth._top;
          _data = std::move(oth._data);
          oth._top = -1;
     }
     return *this;
}

template<typename T>
stack<T>& stack<T>::operator=(const stack& oth)
{
     _top = oth._top;
     _data = oth._data;
     return *this;
}

template<typename T>
bool stack<T>::empty() const
{
     return !(_data.size());
}

template<typename T>
size_t stack<T>::size() const
{
     return _data.size();
}

template<typename T>
void stack<T>::push(const T& val)
{
     _data.push_back(val);
     _top++;
}

template<typename T>
void stack<T>::pop()
{
     _data.pop_back();
     _top--;
}

template<typename T>
const T& stack<T>::top() const
{
     return _data[_top];
}


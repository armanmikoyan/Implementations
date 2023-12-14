template<typename T>
queue<T>::queue()
     : _top{-1}
{}

template<typename T>
queue<T>::queue(const queue& oth)
     : _top{oth._top}
     , _data{oth._data}
{}

template<typename T>
queue<T>::queue(queue&& oth) noexcept
     : _top{oth._top}
     , _data{std::move(oth._data)}
{
     oth._top = -1;
}

template<typename T>
queue<T>& queue<T>::operator=(queue&& oth) noexcept
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
queue<T>& queue<T>::operator=(const queue& oth)
{
     _top = oth._top;
     _data = oth._data;
     return *this;
}

template<typename T>
bool queue<T>::empty() const
{
     return !(_data.size());
}

template<typename T>
size_t queue<T>::size() const
{
     return _data.size();
}

template<typename T>
void queue<T>::push(const T& val)
{
     _data.push_back(val);
     _top++;
}

template<typename T>
void queue<T>::pop()
{
     _data.erase(_data.begin());
}

template<typename T>
const T& queue<T>::front() const
{
     if(empty()) throw std::out_of_range("Queue is empty");
     return _data[0];
}

template<typename T>
const T& queue<T>::back() const
{
     return _data[_top];
}

template <typename T>
vector<T>::vector()
     : _arr{}
     , _size{}
     , _capacity{}
{
}  

template <typename T>
vector<T>::~vector()
{
     delete[] _arr;
}

template <typename T>
vector<T>::vector(size_t sz)
     : _arr{new T[sz]}
     , _size{}
     , _capacity{sz}
{
}  

template <typename T>
vector<T>::vector(vector&& oth) noexcept
     : _arr{oth._arr}
     , _size{oth._size}
     , _capacity{oth._capacity}
{
     oth._arr = nullptr;
     oth._size = 0;
     oth._capacity = 0;
}  

template <typename T>
vector<T>::vector(const vector& oth)
     : _arr{new T[oth._capacity]}
     , _size{oth._size}
     , _capacity{oth._capacity}
{
     for (size_t i = 0; i < _size; ++i)
     {
          _arr[i] = oth._arr[i];
     }
}  
 
template <typename T>
vector<T>::vector(std::initializer_list<T> list)
{
     for (const auto& elem : list)
     {
          push_back(elem);
     }
}  
 
template <typename T>
vector<T>& vector<T>::operator=(const vector& rhs)
{
     if (this != &rhs)
     {
          delete[] _arr;

          _arr = new T[rhs._capacity];
          _size = rhs._size;
          _capacity = rhs._capacity;

          for (size_t i = 0; i < _size; ++i)
          {
               _arr[i] = rhs._arr[i];
          }
     }
     return *this;
}  

template <typename T>
vector<T>& vector<T>::operator=(vector&& rhs) noexcept
{
     if (this != &rhs)
     {
          delete[] _arr;
          _arr = rhs._arr;
          _size = rhs._size;
          _capacity = rhs._capacity;

          rhs._arr = nullptr;
          rhs._size = 0;
          rhs._capacity = 0;     
     }
     return *this;
}

template <typename T>
void vector<T>::push_back(const T& val)
{

     if(_size == _capacity)
     {
          _capacity == 0 ? _capacity = 1 : _capacity *= 2;
          T* tmp = new T[_capacity];
          for (size_t i = 0; i < _size; ++i)
          {
               tmp[i] = _arr[i];
          }
          delete[] _arr;
          _arr = tmp;  
     }
     _arr[_size++] = val;
}

template <typename T>
void vector<T>::pop_back()
{
     if (_size )
     {
          --_size;
     }
}

template <typename T>
void vector<T>::insert(size_t idx, const T& elem)
{
     if (idx > _size)
     {
          throw std::out_of_range("Index is greater than or equal to size");
     }
     if (_size == _capacity)
     {
          _capacity *= 2;
          T* tmp = new T[_capacity * 2];
          for (size_t i = 0; i < _size; ++i)
          {
               tmp[i] = _arr[i];
          }
          delete[] _arr;
          _arr = tmp;
     }
     for (size_t i = _size; i > idx; --i)
     {
          _arr[i] = _arr[i - 1];
     }
     _arr[idx] = elem;
     ++_size;
}

template <typename T>
size_t vector<T>::search(T val)
{
     for (size_t i = 0; i < _size; ++i)
     {
          if (_arr[i] == val)
          {
               return i;
          }
     }
     return -1;
}

template <typename T>
T vector<T>::at(size_t idx)
{
     if (idx > _size)
     {
          throw std::out_of_range("Index is greater than or equal to size");
     }
     return _arr[idx];
}

template <typename T>
T& vector<T>::operator[](size_t idx)
{
     return _arr[idx];
}

template <typename T>
const T& vector<T>::operator[](size_t idx) const 
{
     return _arr[idx];
}


template <typename T>
size_t vector<T>::size() const
{
     return _size;
}

template <typename T>
void vector<T>::resize(size_t size)
{
     if (size != _capacity)
     {
          T* tmp = new T[size];
           _capacity = size;
          if (_size < size)
          {
               for (size_t i = 0; i < _size; ++i)
               {
                    tmp[i] = _arr[i];
               }
               delete[] _arr;
               _arr = tmp;
          }
          else
          {
               _capacity = size;
               _size = size;
               for (size_t i = 0; i < size; ++i)
               {
                    tmp[i] = _arr[i];
               }
               delete[] _arr;
               _arr = tmp;

          }
     }    
    
}

template<typename T>
typename vector<T>::iterator vector<T>::begin()
{
     return iterator(_arr);
}

template<typename T>
typename vector<T>::iterator vector<T>::end()
{
     return iterator(_arr + _size);
}

template<typename T>
typename vector<T>::const_iterator vector<T>::cbegin() const
{
     return const_iterator(_arr);
}

template<typename T>
typename vector<T>::const_iterator vector<T>::cend() const
{
     return const_iterator(_arr + _size);
}


template<typename T>
void vector<T>::erase(iterator pos)
{
     if (pos == end()) return;

     iterator next = pos;
     ++next;

     for (; next != end(); ++pos, ++next)
     {
          *pos = *next;
     }
     --_size;
}

template <typename T>
void vector<T>::traverse() const
{
     for (int i = 0; i < _size; ++i)
     {
          std::cout << _arr[i] << " ";
     }
     std::cout << std::endl;
     std::cout << "size-> " << _size << std::endl;
     std::cout << "capacity-> " << _capacity << std::endl;
}
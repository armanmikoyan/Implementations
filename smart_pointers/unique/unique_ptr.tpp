template<typename T, typename Deleter>
unique_ptr<T, Deleter>::unique_ptr(T* ptr, Deleter deleter)
    : _ptr(ptr)
    , _deleter(deleter)
{
}

template<typename T, typename Deleter>
unique_ptr<T, Deleter>::~unique_ptr()
{
    if constexpr (std::is_same_v<Deleter, std::nullptr_t>)
    {
        std::cout << "defualt without deleter";
        delete _ptr;
    }
    else 
    {
       _deleter(_ptr);
    }
   
}

template<typename T, typename Deleter>
unique_ptr<T, Deleter>::unique_ptr(unique_ptr&& oth) noexcept
        : _ptr(oth._ptr)
    {
        oth._ptr = nullptr;
    }

template<typename T, typename Deleter>
unique_ptr<T, Deleter>& unique_ptr<T, Deleter>::operator=(unique_ptr&& oth) noexcept
{
    if (this != &oth)
    {
        if (!_ptr)
        {
            if constexpr  (std::is_same_v<Deleter, std::nullptr_t>)
            {
                std::cout << "defualt without deleter";
                delete _ptr;
            }
            else
            {
                _deleter(_ptr);
            }
            _ptr =    oth._ptr;
            oth._ptr = nullptr;
        } 
    }
        return *this;
    }

template<typename T, typename Deleter>
T& unique_ptr<T, Deleter>::operator*()
{
    return *_ptr;
}

template<typename T, typename Deleter>
T* unique_ptr<T, Deleter>::operator->()
{
    return _ptr;
}

template<typename T, typename Deleter>
T* unique_ptr<T, Deleter>::get()
{
    return _ptr;
}

template<typename T, typename Deleter>
void unique_ptr<T, Deleter>::reset(T* optional)
{
    if (optional != _ptr)
    {
        delete     _ptr;
        _ptr = optional;    
    }
}

template<typename T, typename Deleter>
T* unique_ptr<T, Deleter>::release()
{
    T* tmp =  _ptr; 
    _ptr = nullptr;
    return     tmp;
}




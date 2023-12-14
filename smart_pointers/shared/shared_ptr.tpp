template<typename T>
Control_block<T>::Control_block()
    : ref_count(new size_t)
    , weak_count(new size_t)
{
}

template<typename T>
Control_block<T>::~Control_block()
{
    delete ref_count;
    delete weak_count;
    delete _ptr;
}


template<typename T>
shared_ptr<T>::~shared_ptr()
{
    deleting();
}

template<typename T>
shared_ptr<T>::shared_ptr(T* p, void(*fptr)(T*))
    :   _control_block(new Control_block<T>)
    ,   _deleter(fptr)
{
    if (p)
    {
        _control_block->_ptr = p;
          ++(*(_control_block->ref_count));
        
    }
}


template<typename T>
shared_ptr<T>::shared_ptr(const shared_ptr& oth)
    : _control_block(oth._control_block)
{
      ++(*(_control_block->ref_count));
}


template<typename T>
shared_ptr<T>::shared_ptr(shared_ptr&& oth) noexcept
    : _control_block(oth._control_block)
{
    oth._control_block = nullptr;
}

template<typename T>
shared_ptr<T>& shared_ptr<T>::operator=(const shared_ptr& oth)
{
    if(this != &oth)
    {
        deleting();
        if(_control_block)
        {
            ++(*(_control_block->ref_count));
        } 
    }
    return *this;
}

template<typename T>
shared_ptr<T>& shared_ptr<T>::operator=(shared_ptr&& oth) noexcept
{
    if(this != oth)
    {
        _control_block = oth._control_block;
        oth._control_block = nullptr;
    }
    return *this;
}

template<typename T>
T* shared_ptr<T>::get()
{
    return _control_block->_ptr;
}

template<typename T>
T* shared_ptr<T>::operator->()
{
    return _control_block->_ptr;
}

template<typename T>
T& shared_ptr<T>::operator*()
{
     return *(_control_block->_ptr);
}


template<typename T>
void shared_ptr<T>::deleting()
{
    if(_control_block)
    {
        --(*_control_block->ref_count);
        if(*(_control_block->ref_count) == 0)
        {
            if(_deleter)
            {
                std::cout << "custom";
                _deleter(_control_block->_ptr);
            }
            else
            {
                std::cout << "default";
                delete _control_block;
            }
        }  
    }
}



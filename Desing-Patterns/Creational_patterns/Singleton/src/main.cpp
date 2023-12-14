#include <iostream>

#include "singleton.hpp"

Singleton* Singleton::_instance = nullptr;

int main() {
    Singleton* obj1 = Singleton::create();   
    Singleton* obj2 = Singleton::create();  
    Singleton* obj3 = Singleton::create();   
}









/*
templated version


#include <iostream>

template<typename T>
class Singleton {
protected:
    Singleton()
    {
        std::cout << "Singleton base\n";
    };
    static T* _instanse;
public:
    static T* get() 
    {
        if(!_instanse)
        {
            _instanse = new T;
        }
        return _instanse;
    } 
     virtual void foo() = 0;
};

class Derived : public Singleton<Derived> {
private:
    friend class Singleton<Derived>;
    Derived()
    {
            std::cout << "Derived \n";
    }
    public:
    void foo(){
             std::cout << "aaaaaa \n";
    }
};

template<typename T> 
T* Singleton<T>::_instanse = nullptr;


int main(){
    Derived* ptr = Singleton<Derived>::get();
    Derived* ptr2 = Singleton<Derived>::get();
    Singleton<Derived>* ptr3 = Singleton<Derived>::get();
    ptr3->foo();
}

*/

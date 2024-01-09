#include <iostream>

template<typename T>
struct is_pointer
{
    constexpr static bool value = false;
};

template<typename T>
struct is_pointer<T*> 
{
    constexpr static bool value = true;
};

template<typename T>
void check(T arg)
{
    std::cout << std::boolalpha << is_pointer<T>::value << "\n";         
}

int main()
{
    int x = 99;
    const int * const ptr = &x;
    check(ptr);
}
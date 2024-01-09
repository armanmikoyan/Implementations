#include <iostream>

template<typename T>
struct is_rvalue_reference
{
    constexpr static bool value = false;
};

template<typename T>
struct is_rvalue_reference<T&&> 
{
    constexpr static bool value = true;
};

int main()
{
    int x = 99;
    int& lvalue_ref = x;
    int&& rvalue_ref = 9;

    std::cout << is_rvalue_reference<decltype(rvalue_ref)>::value << "\n";
}
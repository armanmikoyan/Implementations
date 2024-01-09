#include <iostream>

template<typename T>
struct is_funcamental
{
    constexpr static bool value = false;
};

template<>
struct is_funcamental<char> 
{
    constexpr static bool value = true;
};

template<>
struct is_funcamental<short> 
{
    constexpr static bool value = true;
};

template<>
struct is_funcamental<int> 
{
    constexpr static bool value = true;
};

template<>
struct is_funcamental<long> 
{
    constexpr static bool value = true;
};

template<>
struct is_funcamental<long long> 
{
    constexpr static bool value = true;
};

template<>
struct is_funcamental<unsigned char> 
{
    constexpr static bool value = true;
};

template<>
struct is_funcamental<unsigned short> 
{
    constexpr static bool value = true;
};

template<>
struct is_funcamental<unsigned int> 
{
    constexpr static bool value = true;
};

template<>
struct is_funcamental<unsigned long> 
{
    constexpr static bool value = true;
};

template<>
struct is_funcamental<unsigned long long> 
{
    constexpr static bool value = true;
};

int main()
{
    int x = 99;
    int& lvalue_ref = x;
    int&& rvalue_ref = 9;
    unsigned int uint_ = 99;

    std::cout << is_funcamental<decltype(uint_)>::value << "\n";
}
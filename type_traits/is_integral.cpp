#include <iostream>

template<typename T>
struct is_integral
{
    constexpr static bool value = false;
};

template<>
struct is_integral<char> 
{
    constexpr static bool value = true;
};

template<>
struct is_integral<short> 
{
    constexpr static bool value = true;
};

template<>
struct is_integral<int> 
{
    constexpr static bool value = true;
};

template<>
struct is_integral<long> 
{
    constexpr static bool value = true;
};

template<>
struct is_integral<long long> 
{
    constexpr static bool value = true;
};

template<typename T>
void check(T arg)
{
    if (is_integral<T>::value)
    {
        std::cout << arg << " " << "is integral type!!!\n";
    }
    else
    {
        std::cout << arg << " " << "is not integral type!!!\n";
    }
}

int main()
{
    char char_val      =    97;
    float float_val    =  99.9;
    int int_val        =    99;
    double double_val  = 99.99;
    long long_val      = 99999;

    check(int_val);
}
#include <iostream>

template<typename T>
struct is_floating_point
{
    constexpr static bool value = false;
};

template<>
struct is_floating_point<float> 
{
    constexpr static bool value = true;
};

template<>
struct is_floating_point<double> 
{
    constexpr static bool value = true;
};

template<>
struct is_floating_point<long double> 
{
    constexpr static bool value = true;
};

template<typename T>
void check(T arg)
{
    if (is_floating_point<T>::value)
    {
        std::cout << arg << " " << "is floating point type!!!\n";
    }
    else
    {
        std::cout << arg << " " << "is not floating point type!!!\n";
    }
}

int main()
{
    char char_val           =     97;
    float float_val         =  99.99;
    int int_val             =    999;
    double double_val       = 99.999;
    long double l_double_v  = 99.999;
    long long_val           = 999999;

    check(double_val);
}
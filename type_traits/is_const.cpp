#include <iostream>

template<typename T>
struct is_const
{
    constexpr static bool value = false;
};

template<typename T>
struct is_const<const T>
{
    constexpr static bool value = true;
};

int main()
{
    int x = 10;
    const int cx = 99;
    std::cout << is_const<decltype(cx)>::value << '\n';
}
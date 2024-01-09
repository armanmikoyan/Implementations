#include <iostream>
#include <type_traits>

template<typename T>
struct is_arithmetic
{
    constexpr static bool value = std::is_integral_v<T> || std::is_floating_point_v<T>;
};


int main()
{
    std::cout << is_arithmetic<int>::value << '\n'; 
}
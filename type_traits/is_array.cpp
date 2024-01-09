#include <iostream>

template<typename T>
struct is_array
{
    constexpr static bool value = false;
};

template<typename T>
struct is_array<T[]> 
{
    constexpr static bool value = true;
};

template<typename T, size_t N>
struct is_array<T[N]> 
{
    constexpr static bool value = true;
};

template<typename T>
void check(T arg)
{
    std::cout << std::boolalpha << is_array<T>::value << "\n";         // false
}

int main()
{
    std::cout << std::boolalpha << is_array<int[]>::value << "\n";    // true
    std::cout << std::boolalpha << is_array<int>::value << "\n";     //  false

    int arr[]{1, 2, 3};
    check(arr);      // it wont give true int[] decays into int* int function argument
}
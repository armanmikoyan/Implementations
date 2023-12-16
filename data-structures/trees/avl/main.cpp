#include <iostream>
#include "avl.hpp"


int main()
{
    avl<int> b;
    b.insert(100);
    b.insert(50);
    b.insert(200);
    b.insert(20);
    b.insert(70);
    b.insert(60);
    b.insert(55);
    b.insert(65);
    b.insert(150);
    b.insert(250);
    b.traverse_in();
    std::cout << std::endl;
    std::cout << std::endl;
}
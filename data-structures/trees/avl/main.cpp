#include <iostream>
#include "avl.hpp"


int main()
{
    avl<int> b;
    b.insert(100);
    b.insert(150);
    b.insert(250);
    b.traverse_in();

    std::cout << std::endl;
        b.level_order_traversal();
    std::cout << std::endl;
}
#include <iostream>
#include "bst.hpp"


int main()
{
    bst<int> b;
    b.insert(100);
    b.insert(50);
    b.insert(200);
    b.insert(20);
    b.insert(70);
    b.insert(150);
    b.insert(250);
    b.traverse_in();
    std::cout << std::endl;
    b.level_order_traversal();
}
#include <iostream>
#include "rb.hpp"


int main()
{
    rb<int> rb;
    rb.insert(1);
    rb.insert(7);
    rb.insert(6);
     rb.insert(5);
    rb.insert(4);
     rb.insert(3);
    rb.insert(2);
    rb.insert(0);
     rb.insert(9);
     rb.insert(10);
     rb.insert(8);
    rb.level_order_traversal();
}
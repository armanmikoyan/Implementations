#include <iostream>
#include "rb.hpp"


int main()
{
    rb<int> rb;
    rb.insert(11);
    rb.insert(27);
    rb.insert(66);
    rb.insert(35);
    rb.insert(4);
    rb.insert(13);
    rb.insert(23);
    rb.insert(10);
    rb.insert(93);
    rb.insert(7);
    rb.insert(9);
     rb.level_order_traversal();
}
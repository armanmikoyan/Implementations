#include <iostream>
#include "rb.hpp"


int main()
{
    rb<int> rb;
    rb.insert(11);
    rb.insert(12);
    rb.insert(9);
    rb.insert(29);
    rb.insert(129);
    rb.insert(1);
    rb.insert(5);
    rb.insert(7); 
       
    rb.erase(7);
    rb.erase(9);
    rb.erase(29);
    rb.level_order_traversal();
}
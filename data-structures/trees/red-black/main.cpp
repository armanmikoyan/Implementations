#include <iostream>
#include "rb.hpp"


int main()
{
    rb<int> rb;
    rb.insert(11);
     rb.insert(12);
     rb.insert(9);
    
     rb.erase(9);
     rb.level_order_traversal();

}
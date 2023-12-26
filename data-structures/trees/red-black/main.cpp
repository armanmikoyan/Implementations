#include <iostream>
#include "rb.hpp"


int main()
{
    rb<int> rb;
    rb.insert(50);
    rb.insert(88);
   rb.insert(30);
    rb.insert(26);
       rb.insert(99);

   rb.insert(15);    
       rb.insert(77);
      rb.insert(3);
   
      rb.insert(4);
            rb.insert(16);
               rb.insert(12);
                  rb.insert(57);
                        rb.insert(58);
     rb.level_order_traversal();
}
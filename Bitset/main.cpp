#include <iostream>
#include <vector>
#include "BitVector.hpp"





int main() {
  const int sizeofvector = 99;
  armanstd::bitvector vector(sizeofvector);

  vector.set(0);
  vector.set(99);
  vector.printBits();

}
#include <iostream>
#include "impl.hpp"

int main()
{
    Base b;
    Derived d;
    Base* bptr = &d;

    (bptr->*(bptr->vptr->fptrs[0]))();   //   Derived's overriden foo1
    (bptr->*(bptr->vptr->fptrs[1]))();  //    Derived's not overriden foo2
    (bptr->*(bptr->vptr->fptrs[2]))(); //     Derived's own virtual foo3
}





  //-------------------//
 // intermediate code // 
//-------------------//
/*
struct Base {
   int x;
};

struct Derived : public Base {};


void bfoo(Base* ptr)
{
  ptr->x = 99;
  std::cout << "Called Base::foo x-> " << ptr->x << '\n';
}

void dfoo(Derived* ptr)
{
   ptr->x = 10;
   std::cout << "Called Derived::foo x-> " << ptr->x << '\n' ;
}

struct VTABLE
{
  void (*fptrs[1])(Base*);
};

int main()
{
  Base b;
  Derived d;

  VTABLE bvtbl;
  bvtbl.fptrs[0] = bfoo;

  VTABLE dvtbl;
  dvtbl.fptrs[0] = reinterpret_cast<void(*)(Base*)>(dfoo);

  bvtbl.fptrs[0](&b);
  dvtbl.fptrs[0](&d);
}
*/




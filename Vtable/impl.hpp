class Base;

struct VTABLE {
     //-------------------------//
    // function pointers array //
   //-------------------------//
   void (Base::*fptrs[3])();   
   std::string type_info;  
};

class Base {
public:
    Base()
        : vptr{new VTABLE}
    {
        vptr->fptrs[0] = &Base::foo1;
        vptr->fptrs[1] = &Base::foo2;
        vptr->type_info = typeid(Base).name();  
    }

    virtual void foo1() 
    {
        std::cout << "BASE::FOO1\n";
    }

    virtual void foo2() 
    {
        std::cout << "BASE::FOO2\n";
    }

    VTABLE* vptr;
};


class Derived : public Base {
public:
    Derived()
    {
       vptr->fptrs[0] = static_cast<void (Base::*)()>(&Derived::foo1);
       vptr->fptrs[2] = static_cast<void (Base::*)()>(&Derived::foo3);
       vptr->type_info = typeid(Derived).name();  
    }

    void foo1() override 
    {
        std::cout << "Derived::FOO1\n";
    }

    virtual void foo3()  
    {
        std::cout << "Derived::FOO3\n";
    }
};


#include <iostream>
#include <string>


class Base
{
public:
    Base() { std::cout << "Base+" << std::endl; }
    virtual ~Base() { std::cout << "Base-" << std::endl; }
    virtual void foo() const { std::cout << "Base.foo()" << std::endl; }
    virtual void bar() const { std::cout << "Base.bar()" << std::endl; }
};

class Derived : public Base
{
public:
    Derived() { std::cout << "Derived+" << std::endl; }
    ~Derived() { std::cout << "Derived-" << std::endl; }
    void foo() const override { std::cout << "Derived.foo()" << std::endl; }
    void tartar() const { std::cout << "Derived.tartar()" << std::endl; }
};

// typedef void (Base::*func)();
typedef void (Base::*ConstMemFuncType)() const;
// typedef void FuncType() const;
// typedef FuncType K::* MemFuncType;


int main()
{
    Base* b = new Derived();
    b->foo();
    b->bar();
    // doed not exist in Base
    // b->tartar();
    delete b;
    
    std::cout << "//===========//" << std::endl;
    
    Base& base_as_derived = *(new Derived());
    long* p = (long*)(&base_as_derived);
    ConstMemFuncType* vtab = (ConstMemFuncType*)(p[0]);

    base_as_derived.foo();
    base_as_derived.bar();

    ConstMemFuncType* my_vtab = new ConstMemFuncType[4];

    my_vtab[0] = vtab[0]; // \  I added these lines in step two after i got an
    my_vtab[1] = vtab[1]; // /  access violation
    my_vtab[2] = &Base::bar;
    my_vtab[3] = &Base::foo;

    p[0] = (long)(my_vtab);

    base_as_derived.foo();
    base_as_derived.bar();

    delete[] my_vtab;
    delete &base_as_derived;
    
    return 0;
}

// Base+
// Derived+
// Derived.foo()
// Base.bar()
// Derived-
// Base-
// //===========//
// Base+
// Derived+
// Derived.foo()
// Base.bar()
// Derived.foo()
// Base.bar()
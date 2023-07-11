#include <iostream>

using namespace std;

class Base
{
public:
    Base() {cout<<"Base built"<<endl;}
    virtual ~Base() {cout<<"Base destroyed"<<endl;}
};

class Derived : public Base
{
public:
    Derived() {cout<<"Derived built"<<endl;}
    ~Derived() {cout<<"Derived destroyed"<<endl;}
};

class AnotherClass : public Base
{
public:
    AnotherClass() {cout<<"AnotherClass built"<<endl;}
    ~AnotherClass() {cout<<"AnotherClass destroyed"<<endl;}
    
};

int main()
{
    // c
    double value = 25;
    double a = (int)(value) + 5.3;
    cout<<a<<endl;
    
    // c++
    double d = static_cast<int>(value) + 5.3;
    cout<<d<<endl;
    
    // punning
    // double s = reinterpret_cast<AnotherClass*>(&value) + 5.3;
    
    Derived* derived = new Derived();
    Base* base = derived;
    // theoretically it checks
    Derived* dc = dynamic_cast<Derived*>(base);
    AnotherClass* ac = dynamic_cast<AnotherClass*>(base);
    // in c++ NULL is 0 or 0L
    if (ac == NULL) {cout<<"failure"<<endl;}
    if (ac) {cout<<"success"<<endl;}
    
    return 0;
}
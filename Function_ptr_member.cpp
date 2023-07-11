
#include <iostream>

class C
{
public:
    C() { std::cout << "C+" << std::endl; };
    ~C() { std::cout << "C-" << std::endl; };
    
    int m_get() {
        return 42;
    }
    int m_get_other() {
        return 24;
    }
};

int main()
{
    using mem = int (C::*)();
    mem get = &C::m_get;

    C c;
    int d = -1;
    
    d = (c.*get)();
    std::cout << d << std::endl;
    
    get = &C::m_get_other;
    d = (c.*get)();
    std::cout << d << std::endl;
    
    c.~C();
    
    // cannot be done to constructor or destructor
    // using constructor = C (C::*)();
    // constructor con = &C::C;
    // using destructor = void (C::*)();
    // destructor des = &C::~C;

    return 0;
}
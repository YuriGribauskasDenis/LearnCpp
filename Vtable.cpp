
#include <iostream>


class B
{
public:
    virtual void bar() const
    {
      std::cout << "This is B's implementation of bar" << std::endl;
    }
    virtual void qux() const
    {
      std::cout << "This is B's implementation of qux" << std::endl;
    }
};

class C : public B
{
public:
    void bar() const override
    {
      std::cout << "This is C's implementation of bar" << std::endl;
    }
};

int main()
{
    std::cout << "Hello World" << std::endl;
    
    B* b = new C();
    b->bar();
    
    std::cout << "Bye World" << std::endl;

    return 0;
}
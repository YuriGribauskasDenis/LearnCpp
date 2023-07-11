#include <iostream>
#include <string>

using namespace std;

class Foo
{
private:
    int m_foo;
public:
    // single parameter constructor, can be used as an implicit conversion
    Foo (int foo) : m_foo (foo) {}
    
    int GetFoo () { return m_foo; }
    };
void DoBar (Foo foo)
{
    int i = foo.GetFoo ();
}

int main ()
{
    // The argument is not a Foo object, but an int. However,
    // there exists a constructor for Foo that takes an int
    // so this constructor can be used to convert the parameter to the correct type.
    // The compiler is allowed to do this once for each parameter.
    DoBar (42);
}
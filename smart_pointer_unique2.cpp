
#include <iostream>
#include <memory>

using namespace std;

struct Foo {
    Foo() {cout << "Foo [" << this << "] constructed\n";}
    virtual ~Foo() {cout << "Foo [" << this << "] destructed\n";}
};

void sink(unique_ptr<Foo> p) {
    cout << "Sink owns Foo [" << p.get() << "]\n";
}

unique_ptr<Foo> source() {
    cout << "Creating Foo in source\n";
    return unique_ptr<Foo>(new Foo);
}

int main(int argc, char** argv) {
    cout << "Calling source\n";
    unique_ptr<Foo> pmain = source();  // Can also be written as
                                       // auto pmain = source();

    cout << "Now pmain owns Foo [" << pmain.get() << "]\n";
    cout << "Passing it to sink\n";
    // sink(pmain);                    // ERROR! can't copy unique_ptr
    sink(move(pmain));              // OK: can move it!

    cout << "Main done\n";
    return 0;
}
#include <iostream>
#include <memory>
using namespace std;

struct Foo {
    Foo() {cout << "Foo [" << this << "] constructed\n";}
    virtual ~Foo() {cout << "Foo [" << this << "] destructed\n";}
};

int main(int argc, char** argv) {

    // .. some code
    {
        unique_ptr<Foo> fp(new Foo());

        // unique_ptr<Foo> fp2(fp);    // ERROR! can't copy unique_ptr
        unique_ptr<Foo> fp3;
        // fp3 = fp;                   // ERROR! can't assign unique_ptr

        cout << "Exiting scope\n";
    } // fp will be destroyed, and will destruct the pointed object
    cout << "Exiting program\n";

    return 0;
}
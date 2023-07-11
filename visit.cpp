
#include <iostream>
#include <variant>

using namespace std;

class One {};
class Two {};
class Three {};
class Four {};

class MyVisit
{
public:
    void operator()(One&) { cout << "One" << endl; }
    void operator()(Two&) { cout << "Two" << endl; }
    void operator()(Three&) { cout << "Yhree" << endl; }
    void operator()(Four&) { cout << "Four" << endl; }
};

int main()
{
    variant<One, Two, Three, Four> smth { Three() };
    visit(MyVisit(), smth);



    return 0;
}
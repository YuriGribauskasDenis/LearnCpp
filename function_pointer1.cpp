#include <iostream>

using namespace std;

int HelloWorld(const char* name, const int& number)
{
    cout<<"Hello World from "<<name<<" "<<number<<" times"<<endl;
    return 0;
}

int main()
{
    const char* name { "Yurii" };
    auto function1 = &HelloWorld;
    // there is implicit conversion, so:
    auto function2 = HelloWorld;
    function1(name, 1);
    function2(&name[0], 2);

    
    int(*newName)(const char*, const int&) = HelloWorld;
    newName("Denis");
    
    typedef int(*newFuncTypeName)(const char*, const int&);
    newFuncTypeName myFunction = HelloWorld;
    myFunction("Yuriy");
    
}
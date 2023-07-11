#include <iostream>

using namespace std;

class Base
{
public:
    Base(){cout<<"Base built"<<endl;}
    virtual ~Base(){cout<<"Base destroyed"<<endl;}
};

class Derived : public Base
{
public:
    Derived(){m_data = new int[5]; cout<<"Derived built"<<endl;}
    ~Derived(){delete[] m_data;cout<<"Derived destroyed"<<endl;}
public:
    int* m_data;
};

int main()
{
    Base* base = new Base();
    delete base;
    cout<<"------------------"<<endl;
    Derived* derived = new Derived();
    delete derived;
    cout<<"------------------"<<endl;
    Base* poly = new Derived();
    delete poly;
    cout<<"------------------"<<endl;
    return 0;
}

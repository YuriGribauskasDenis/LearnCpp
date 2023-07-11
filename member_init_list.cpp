
#include <iostream>
#include <memory>

using namespace std;

class B
{
public:
    B() : m_a(0), m_b(0) { cout << "DefConstr" << endl; }
    B(int a, int b) : m_a(a), m_b(b) { cout << "Constr" << endl; }
private:
    int m_a;
    int m_b;
};

class D : public B
{
public:
    D(int a, int b) : B{a,b} {}
};

class C
{
public:
    C(int a, int b)
        : m_cb{a,b} // m_cb (B(a,b))
    {
        // m_cb = B(a,b);
    } 
private:
    B m_cb;
};

int main()
{
    D d(1,2);
    C c(3,4);

    return 0;
}
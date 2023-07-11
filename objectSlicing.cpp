
#include <iostream>

class A {
public:
    A() { m_foo = 0; }
    A(int val) { m_foo = val; }
    virtual A& operator= (const A& a) {
        assign(a);
        return *this;
    }
    const int& getFoo() const {
        return m_foo;
    }
protected:
    void assign(const A& a) {
        // copy members of A from a to this
        m_foo = a.getFoo();
    }
private:
    int m_foo;
};

class B : public A {
public:
    B() { m_bar = 0; }
    B(int valA, int valB) : A(valA) { m_bar = valB; }
    virtual B& operator= (const A& a) {
        if (const B* b = dynamic_cast<const B*>(&a)) {
            assign(*b);
        } else {
            std::cerr << "bad assignment" << std::endl;
            std::cerr << "value did not change" << std::endl;
        }
        return *this;
    }
    const int& getBar() const {
        return m_bar;
    }
protected:
    void assign(const B& b) {
        A::assign(b); // Let A's assign() copy members of A from b to this
        // copy members of B from b to this
        m_bar = b.getBar();
    }
private:
    int m_bar;
};

int main()
{
    // base case
    B b(1, 2);
    A a = b;
    std::cout << a.getFoo() << std::endl;
    // std::cout << a.getBar() << std::endl;
    
    std::cout << "Hello World" << std::endl;
    
    // treacherous case
    B b1(3, 4);
    B b2(5, 6);
    A& a_ref = b2;
    a_ref = b1;
    //b2 now contains a mixture of b1 and b2!
    
    std::cout << a_ref.getFoo() << std::endl;
    // std::cout << a_ref.getBar() << std::endl;
    
    std::cout << b2.getFoo() << std::endl;
    std::cout << b2.getBar() << std::endl;
    
    std::cout << "Good-bye World" << std::endl;
    
    

    return 0;
}
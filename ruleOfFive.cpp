#include <iostream>

class Resource {
private:
    int m_x;
public:
    Resource() : m_x{ 0 } { }
    Resource(int x) : m_x{ x } { }
    Resource(const Resource& other)  : m_x{ other.m_x } { }
public:
    const int& getX() const
    { return m_x; }
};

template <typename T> class A {
private:
    T* m_p;
public:
    A() : m_p{ new T{ } } { }
    A(T* p) : m_p{ new T{ *p } } { }
    A(const A& other) : m_p{ new T{ *(other.m_p) } } { }
    A(A&& other) : m_p{ new T{ *(other.m_p) } } {
       other.m_p = nullptr;
    }
    A& operator=(const A& other) {
        if (this != &other) {
            delete m_p;
            m_p = nullptr;
            m_p = new T(*(other.m_p));
        }
        return *this;
      }
      A& operator=(A&& other) noexcept {
        if (this != &other) {
            delete m_p;
            m_p = other.m_p;
            other.m_p = nullptr;
        }
        return *this;
    }
    ~A() {
        delete m_p;
    }
public:
    T* getP() const {
        return m_p;
    }
};

int main()
{
    Resource r(2);
    Resource* p_r = &r;
    Resource* p_r2 = new Resource(*p_r);
    std::cout << p_r2->getX() << std::endl;
    A <Resource> a;
    std::cout << a.getP()->getX() << std::endl;
    A <Resource> ap(p_r);
    std::cout << ap.getP()->getX() << std::endl;
    A <Resource> a2(a);
    std::cout << a2.getP()->getX() << std::endl;
    A <Resource> a3 = std::move(a);
    std::cout << a3.getP()->getX() << std::endl;
    A<Resource> a7(new Resource(7));
    std::cout << a7.getP()->getX() << std::endl;
    a2 = ap;
    std::cout << a2.getP()->getX() << std::endl;
    a2 = std::move(a7);
    std::cout << a2.getP()->getX() << std::endl;
}
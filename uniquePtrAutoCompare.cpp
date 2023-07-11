
#include <iostream>
#include <memory>

class Widget
{
public:
    Widget() : m_le(0), m_he(0) {}
    Widget(int le, int he = 0) : m_le(le), m_he(he) {}
    const int& GetLe() const { return m_le; }
    const int& GetHe() const { return m_he; }
    bool operator==(const Widget& other) const {
        return m_le == other.m_le && m_he == other.m_he;
    }
    auto operator<(const Widget& other) const {
        if (m_le == other.m_le) {
            return m_he < other.m_he;
        } else {
            return m_le < other.m_le;
        }
    }
    bool operator>(const Widget& other) const {
        return !(*this < other);
    }
    bool operator<=(const Widget& other) const {
        return *this < other || *this == other;
    }
    bool operator>=(const Widget& other) const {
        return *this > other || *this == other;
    }
private:
    int m_le;
    int m_he;
};

auto checkPtr(const auto& somePtr) {
    if (somePtr) {
        std::cout << "pointer is still here" << std::endl;
        return true;
    } else {
        std::cout << "pointer is empty" << std::endl;
        return false;
    }
}

int main()
{
    std::unique_ptr<Widget> w1(new Widget(10));
    std::unique_ptr<Widget> w2;
    checkPtr(w2);
    w2 = std::make_unique<Widget>(10, 10);
    checkPtr(w2);
    auto w3 = std::make_unique<Widget>(10, 10);
    
    auto derefLess = [](const auto& p1, const auto& p2){ return *p1 < *p2; };
    
    std::cout << (*w1 < *w2) << std::endl;
    std::cout << derefLess(w1, w2) << std::endl;
    std::cout << (*w1 > *w2) << std::endl;
    std::cout << (*w1 == *w2) << std::endl;
    std::cout << (*w3 <= *w2) << std::endl;
    
    checkPtr(w3);
    
    
    return 0;
}
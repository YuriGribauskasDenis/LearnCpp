
#include <iostream>
#include <vector>


template<typename T>
void f(const T& param) {
    std::cout << param->getI() << std::endl;
    std::cout << typeid(T).name() << std::endl;
    std::cout << typeid(param).name() << std::endl;
}

class Widget {
public:
    Widget() : m_i(0) {}
    Widget(int i) : m_i(i) {}
    const int& getI() const { return m_i; }
private:
    int m_i;
};

std::vector<Widget> createVec() {
    return std::vector<Widget>{Widget{6}, Widget{7}, Widget{8}};
}

int main()
{
    const auto vw = createVec();
    if (!vw.empty()) {
        f(&vw[1]);
    }

    return 0;
}
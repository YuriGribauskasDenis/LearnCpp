
#include <bits/stdc++.h>
#include <variant>
 
template <class A, class B>
std::variant<A, B> findMin(A a, B b) {
    return (a < b) ? a : b;
}

int main()
{
    std::visit([](const auto& x) { std::cout << x; }, findMin(4, 3.44));
    std::cout << std::endl;
    
    std::variant<double, int> my_variant = findMin(5.4, 3);
    std::visit([](const auto& x) { std::cout << x; }, my_variant);
    std::cout << std::endl;
    
    std::cout << typeid(my_variant).name() << std::endl;
    
    if (std::holds_alternative<int>(my_variant)) {
        std::cout << "Variant is of type int" << std::endl;
    }
    if (std::holds_alternative<double>(my_variant)) {
        std::cout << "Variant is of type double" << std::endl;
    }

    return 0;
}
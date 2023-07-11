
#include <iostream>

// auto Add(T1 arg1, T2 arg2) {
// return (args1 + args2)
template <class... T>
auto Add(T ...args) {
    // () - fold expression
    // apply operator to all arguments in pack
    // return (args + ...);
    // return ( 0 + ... + args);
    return (... + args);
}

int main()
{
    auto x = Add(1, 1, 1.75);
    std::cout << x << std::endl;

    return 0;
}
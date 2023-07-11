
#include <iostream>

void foo(int, float) {}

template<class... T> auto callFoo1(T&& ...args) {
    //return [args...]() {
    return [args...] {
        foo(args...);
    };
}

template<class... T> auto callFoo2(T&& ...args) {
    return [... captured = std::forward<T>(args)]() mutable {
        foo(std::forward<T>(captured)...);
    };
}

int main()
{
    const auto lambda1 = callFoo1(1, 2.3);
    lambda1();
    
    // we need mutable so const will not be added
    // const forbid forwarding, we need arguments exactly as they are passed
    // right value and not by value
    auto lambda2 = callFoo1(1, 2.3);
    lambda2;

    return 0;
}
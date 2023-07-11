
#include <iostream>

using namespace std;

int main() {
    constexpr int n = 123;
    // static_assert directive checks a static (constexpr) condition during compile time
    // static_assert(n == 456, "The constexpr value is not 456."); 
    constexpr float f = 1.f;
    constexpr float f2 = f;
    // yes
    const int n2 = 456;
    // no
    // int n2 = 456;
    constexpr int n3 = n2;
    
    // --------------------------
    
    // constexpr int (*lambda1) (int, int)  = [] (int x, int y) { return x + y; };
    constexpr auto lambda1 = [] (int x, int y) { return x + y; };
    static_assert(lambda1(10, 20) == 30, "Lambda is wrong");
    
    // constexpr int (*lambda2) (int, int)  = [] (int x, int y) { return x + y; };
    auto lambda2 = [] (int x, int y) constexpr { return x + y; }; 
    static_assert(lambda2(10, 20) == 30, "Lambda is wrong");
    
    
    return 0;
}
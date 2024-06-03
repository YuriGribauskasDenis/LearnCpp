
#include <type_traits>
#include <iostream>

constexpr int foo_compile_time() {
    // force compile version - always return true
    if constexpr (std::is_constant_evaluated()) {
        return 5;
    } else {
        return 10;
    }
}

constexpr int foo_run_time() {
    // runtime check
    if (std::is_constant_evaluated()) {
        return 15;
    } else {
        return 20;
    }
}

int main()
{
    std::cout << foo_compile_time() << std::endl;;
    const auto k01 = foo_compile_time();
    std::cout << k01 << std::endl;;
    constexpr auto k02 = foo_compile_time();
    std::cout << k02 << std::endl;;

    std::cout << "//---------------------------//" << std::endl;;

    std::cout << foo_run_time() << std::endl;;
    const auto r01 = foo_run_time();
    std::cout << r01 << std::endl;;
    constexpr auto r02 = foo_run_time();
    std::cout << r02 << std::endl;;
    
    return 0;
}
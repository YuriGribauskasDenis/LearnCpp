
#include <iostream>

struct Widget {
    static const int value = 42;
};

int main()
{
    const auto add1 = []<class ...T>(T ...args) {
        return (... + args );
    };
    std::cout << add1(1, 2.75) << std::endl;
    
    // no access to parameter type - every access will need a decltypr
    const auto add2 = [](auto ...args) {
        return ( decltype(args)::value + ... );
    };
    auto w =add2(Widget{}, Widget{});
    std::cout << w << std::endl;

    return 0;
}
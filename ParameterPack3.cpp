
#include <iostream>

// meta programming
// parameters to another template
// compile type sum
// ope template and recursive sum
template <int I, int ...Rest>
struct Sum {
    static const int value = I + Sum<Rest...>::value;
};

// specialization to end recursion
template<int I>
struct Sum<I> {
    static const int value = I;
};


int main()
{
    auto z = Sum<1,2,3,5,8,13,21>::value;
    std::cout << z << std::endl;

    return 0;
}
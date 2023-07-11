
#include <bits/stdc++.h>
 
template <class A, class B>
auto findMin(A a, B b) -> decltype(a < b ? a : b)
{
    return (a < b) ? a : b;
}

int main()
{
    std::cout << findMin(4, 3.44) << std::endl;

    std::cout << findMin(5.4, 3) << std::endl;

    std::cout << typeid(findMin(5.4, 3)).name() << std::endl;

    return 0;
}
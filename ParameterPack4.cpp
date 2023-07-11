// https://www.scs.stanford.edu/~dm/blog/param-pack.html
// https://www.youtube.com/watch?v=lyDGcdqEhqI&t=79s&pp=ygUOcGFyYW1ldGVyIHBhY2s%3D

#include <iostream>

// https://www.scs.stanford.edu/~dm/blog/param-pack.html
// number of parameters
// compile time extruction of arguments in parameter pack
template<class... T>
struct Size {
    static const std::size_t value = sizeof...(T);
};


int main()
{
    auto k = 42u;
    std::cout << k << std::endl;

    return 0;
}
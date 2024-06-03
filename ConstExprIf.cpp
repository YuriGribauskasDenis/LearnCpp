
#include <type_traits>
#include <iostream>
#include <string>


template <typename T>
int length(const T& value) {
    if constexpr (std::is_integral<T>::value) {
        return value;
    } else {
        return value.length();
    }
}

int main()
{
    int k{ 12 };
    std::string line{ "como griadesh" };
    std::cout << length(k) << std::endl;;
    std::cout << length(line) << std::endl;;

    std::cout << "//---------------------------//" << std::endl;;


    return 0;
}

#include <iostream>
#include <string>
#include <type_traits>
 
template <typename T>
auto length(const T& value) {
    if constexpr ( std::is_integral<T>::value ) {
        return value;
    } else {
        return value.length();
    }
}

int main() 
{ 
    int n{ 10 };
    std::string s{ "abc" };
    
    std::cout << "n = " << n << " with length " << length(n) << std::endl;
    std::cout << "s = " << s << " with length " << length(s) << std::endl;
    
     
    return 0; 
}
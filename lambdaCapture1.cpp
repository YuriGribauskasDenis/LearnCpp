
#include <iostream>
#include <algorithm>
#include <iostream>


int main()
{
    std::cout << "Hello World" << std::endl;
    
    std::vector<int> v {2,3,7,11,23};
    std::for_each(v.begin(), v.end(), [](int x){
        std::cout << x << " ";
    });
    std::cout <<  std::endl;
    
    std::cout << "Bye World" << std::endl;

    return 0;
}
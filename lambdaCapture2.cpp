
#include <iostream>
#include <algorithm>
#include <iostream>


int main()
{
    std::cout << "Hello World" << std::endl;
    
    int d = 7;
    std::cout << d << std::endl;
    std::vector<int> v {2,3,7,11,14,20,23};
    std::for_each(v.begin(), v.end(), [&d](int x){
        if (0 == x % d)
        {
            std::cout << x << " divisible by " << d << std::endl;
        }
        else
        {
            std::cout << x << " NOT divisible by " << d << std::endl;
        }
        d = 10;
    });
    std::cout <<  std::endl;
    std::cout << d << std::endl;
    
    std::cout << "Bye World" << std::endl;

    return 0;
}

#include <iostream>
#include <algorithm>
#include <iostream>


struct
{
    void operator() (int x)
    {
        std::cout << x << " ";
    }
} printer;

int main()
{
    std::cout << "Hello World" << std::endl;
    
    std::vector<int> v {2,3,7,11,23};
    std::for_each(v.begin(), v.end(), printer);
    std::cout <<  std::endl;
    
    std::cout << "Bye World" << std::endl;

    return 0;
}
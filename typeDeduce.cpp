
#include <bits/stdc++.h>
 
int fun1() { return 10; }
char fun2() { return 'g'; }
 
int main()
{
    decltype(fun1()) x;
    decltype(fun2()) y;
    decltype(sqrt(12)) z;
    decltype((float)sqrt(12)) s;
 
    std::cout << typeid(x).name() << std::endl;
    std::cout << typeid(y).name() << std::endl;
    std::cout << typeid(z).name() << std::endl;
    std::cout << typeid(s).name() << std::endl;
 
    return 0;
}
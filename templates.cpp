#include <iostream>

using namespace std;

// class = typename but anyway
// int is not a class so for clarity
template<typename T>
void Print(T value)
{
    cout<<value<<endl;
}

int main()
{
    // function is created during compilation when we call it
    // before it does not exist
    Print(1);
    Print(1.3);
    Print("Yuri");
    //explicit type specification
    Print<int>(2);
}


#include <iostream>

using namespace std;

int main()
{
    // 1 - a++
    // 2 - a-> // *this->member works as *member
    // 3 - *a
    // 4 - ++a
    int* a = new int(5);
    cout << *a << endl;
    ++*a;
    cout << *a << endl;
    (*a)++;
    cout << *a << endl;

    return 0;
}
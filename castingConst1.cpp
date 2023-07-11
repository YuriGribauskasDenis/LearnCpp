
#include <iostream>

using namespace std;

int main()
{
    int x = 50;
    const int* y = &x;
    cout << "old value is " << *y << endl;
    int* z = const_cast<int*>(y);
    *z = 100;
    cout << "new value is "<< *y << endl;

    return 0;
}
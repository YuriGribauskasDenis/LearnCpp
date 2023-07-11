
#include <iostream>
#include <string>
#include <memory>

using namespace std;

void func(const unique_ptr<string>& cp) {
    if (cp) {
        cout << *cp << endl;
    } else {
        cout << "Empty pointer" << endl;
    }
}

int main()
{
    unique_ptr<string> p_unique = make_unique<string>("Live Long");
    // unique_ptr<string> p_unique1(p_unique);
    unique_ptr<string> p_unique2 = move(p_unique);
    func(p_unique);
    func(p_unique2);

    return 0;
}
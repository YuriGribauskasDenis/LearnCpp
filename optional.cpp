
#include <iostream>
#include <optional>
#include <string>

using namespace std;

optional<string> readFile(const bool& flag) {
    if (flag) {
        return "success";
    } else {
        return {};
    }
}

int main()
{
    optional<string> data = readFile(false);
    if (data) {
        cout << *data << endl;
    } else {
        cout << "something went wrong" << endl;
    }

    return 0;
}
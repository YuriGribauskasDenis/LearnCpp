#include <iostream>
#include <vector>
using namespace std;

class Foo
{
    int number;
public:
    Foo(const int& i) : number{i} {cout<<"Created"<<endl;}
    Foo(const Foo& other) : number{other.number} {cout<<"Copied"<<endl;}
    int& GetN() {return number;}
    const int& GetN() const {return number;}
};

void setVector(vector<Foo>& vec, int start, int count) {
    for (int i = 0; i < count; i++) {
        vec.emplace_back(start + i);
    }
}

void printVector(vector<Foo>& vec) {
    for (const auto& el : vec) {
        cout << el.GetN() << " ";
    }
    cout << endl;
}

void emptyVector(vector<Foo>& vec) {
    vec.clear();
}

int main()
{
    vector<Foo> one; 
    setVector(one, 10, 5); 
    printVector(one); 
    emptyVector(one); 
    printVector(one); 

    return 0; 
}
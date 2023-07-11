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

void setVector(vector<Foo*>& vec, int start, int count) {
    for (int i = 0; i < count; i++) {
        vec.push_back(new Foo(start + i));
    }
}

void printVector(vector<Foo*>& vec) {
    for (const auto& el : vec) {
        cout << el->GetN() << " ";
    }
    cout << endl;
}

void emptyVector(vector<Foo*>& vec) {
    for (auto& el : vec) {
        delete el; 
    }
    vec.clear();
}

int main() 

{
    vector<Foo*> pone; 
    setVector(pone, 10, 5); 
    printVector(pone); 
    emptyVector(pone); 
    printVector(pone); 

    return 0; 
}
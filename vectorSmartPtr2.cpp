#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Foo
{
    int number;
public:
    Foo(const int& i) : number{i} {cout<<"Created"<<endl;}
    Foo(const Foo& other) : number{other.number} {cout<<"Copied"<<endl;}
    ~Foo() {cout<<"Deleted"<<endl;}
    int& GetN() {return number;}
    const int& GetN() const {return number;}
};

void setVector(vector<shared_ptr<Foo>>& vec, int start, int count) {
    for (int i = 0; i < count; i++) {
        vec.push_back(make_shared<Foo>(start + i));
        // vec.push_back(shared_ptr<Foo>(new Foo(start + i));
    }
}

void printVector(vector<shared_ptr<Foo>>& vec) {
    for (const auto& el : vec) {
        cout << el->GetN() << " ";
    }
    cout << endl;
}

void emptyVector(vector<shared_ptr<Foo>>& vec) {
    vec.clear();
}

int main() 

{
    vector<shared_ptr<Foo>> pone; 
    setVector(pone, 10, 5); 
    printVector(pone); 
    emptyVector(pone); 
    printVector(pone); 

    return 0; 
}
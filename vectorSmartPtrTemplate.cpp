#include <iostream>
#include <vector>
#include <memory>

using namespace std;

template <class T>
class Data
{
public:
    Data(T data) : m_data{data} { cout << "Created" << endl;}
    Data(const Data& other) : m_data{other.m_data} { cout << "Copied" << endl;}
    ~Data() { cout << "Destroyed" << endl;}
    const T& GetData() const {return m_data;}
    void PrintData() {cout << GetData() << endl;}
private:
    T m_data;
};

template <class T>
void setVector(vector<unique_ptr<Data<T>>>& vec, int start, int count) {
    for (int i = 0; i < count; i++) {
        vec.push_back(make_unique<Data<T>>(start + i));
    }
}

template <class T>
void printVector(const vector<unique_ptr<Data<T>>>& vec) {
    for (const auto& el : vec) {
        cout << el->GetData() << " ";
        // el->PrintData();
    }
    cout << endl;
}

template <class T>
void emptyVector(vector<unique_ptr<Data<T>>>& vec) {
    vec.clear();
}

int main()
{
    vector<unique_ptr<Data<int>>> vec;
    setVector(vec, 10, 5);
    printVector(vec);
    emptyVector(vec);
    printVector(vec);
}
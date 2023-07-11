#include <iostream>
#include <vector>

using namespace std;

void PrintValue(const int& value)
{
    cout<<"value: "<<value<<endl;
}

void ForEach(const vector<int>& values, void(*func)(const int&))
{
    for (const int& value : values) // auto& cause vector has const int
        func(value);
}

int main()
{
    vector<int> values = {1,2,3,4,5,6,7};
    ForEach(values, PrintValue);
}

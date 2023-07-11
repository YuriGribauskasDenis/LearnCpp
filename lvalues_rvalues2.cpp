#include <iostream>
#include <vector>
#include <functional>

using namespace std;

//void ForEach(const vector<int>& values, function<void(const int&)> func)
void ForEach(const vector<int>& values, const function<void(const int&)>& func)
{
    for (const int& value : values) // auto& cause vector has const int
        func(value);
}

int main()
{
    vector<int> values = {1,2,3,4,5,6,7};
    int a = 55;
    //auto lambda = [&a](const int& value){cout<<a<<" value: "<<value<<endl;};
    auto lambda = [&a](const int& value)mutable{a = 6;cout<<a<<" value: "<<value<<endl;};
    cout<<a<<endl;
    ForEach(values, lambda);
    cout<<a<<endl;
}
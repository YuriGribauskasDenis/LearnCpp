#include <iostream>
#include <vector>
#include <functional>

using namespace std;

void ForEach(const vector<int>& values, void(*func)(const int&))
{
    for (const int& value : values) // auto& cause vector has const int
        func(value);
}

void ForEach2(const vector<int>& values, const std::function<void(const int&)>& func)
{
    for (const int& value : values) // auto& cause vector has const int
        func(value);
}

int main()
{
    vector<int> values = {1,2,3,4,5,6,7};
    auto lambda = [](const int& value){cout<<"value: "<<value<<endl;};
    ForEach(values, lambda);
    
    int a = 5;
    int b = 2;
    auto lambda2 = [a, &b](const int& value){
        cout<<"value: "<<value<<endl;
        cout<<"augment: "<< a << " " << b <<endl;
    };
    ForEach2(values, lambda2);
}
#include <iostream>
#include <vector>
#include <functional>

using namespace std;

void ForEach(const vector<int>& values, const std::function<void(const int&)>& func)
{
    for (const int& value : values) // auto& cause vector has const int
        func(value);
}

int main()
{
    vector<int> values = {1,2,3,4,5,6,7};
    int n = 0;
    cout<<"mutable: "<< n << endl;
    auto lambda = [=](const int& value) mutable {
        if (value > 5) {
            n++;
            cout<<"value: "<<value<<endl;
            cout<<"mutable: "<<n<<endl;
        }
    };
    ForEach(values, lambda);
    cout<<"mutable: "<< n << endl;
}
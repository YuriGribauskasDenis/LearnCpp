#include <iostream> 

using namespace std; 

int GetValue()
{
    // temporarily val, it has no storage
    return 10; // returns rval
}

int& GetValue2()
{
    static int value = 10;
    return value; // returns lval
}

void SetValue(int value)
{
}

void SetValue2(int& value)
{
}

void SetValue3(const int& value)
{
}

int main()
{ 
    int i1 = 10; // lval = rval
    int i2 = GetValue(); // lval = rval
    int a = i1; // lval = lval
    GetValue2() = 11;
    int i3 = GetValue2(); // lval = lval
    SetValue(i3);
    SetValue(10);
    // can't take lval ref fom rval
    // can take lval ref only fom lval
    SetValue2(i3);
    //SetValue2(10);
    //special rool
    // lval can take a const ref fom rval
    // int& k = 10;
    const int& k = 10;
    //compiler will do next under the hood
    // int temp = 10;
    // const int& k = temp;
    SetValue3(i3);
    SetValue3(10);
    
    return 0;
} 
#include <iostream>

using namespace std;

struct Entity
{
    int x, y;
};

int main()
{
    int a = 50;
    double value1 = a;
    double value2 = (double)a;
    double value3 = *(double*)&a;
    double& value4 = *(double*)&a;
    cout<<a<<", "<<value4<<endl;
    // crush
    // value4 = 2.0;
    //---------------------------
    Entity e = { 5, 8 };
    int* position = (int*)&e;
    cout<<position[0]<<", "<<position[1]<<endl;
    int y1 = e.y;
    int& y2 = *(int*)((char*)&e + 4);
    cout<<y1<<", "<<y2<<endl;
    
    return 0;
}
#include <iostream>

using namespace std;

struct Vector2
{
    float x, y;
};

struct Vector4
{
    union
    {
        struct
        {
            float x, y, z, w;
        };
        struct
        {
            Vector2 a, b;
        };
        
    };
};

void PrintVector2(const Vector2& vector)
{
    cout<<vector.x<<", "<<vector.y<<endl;
}

int main()
{
    Vector4 vector = { 1.0f, 2.0f, 3.0f, 4.0f};
    vector.x *= 10;
    cout<<vector.x<<", "<<vector.y<<endl;
    PrintVector2(vector.a);
    
    return 0;
}
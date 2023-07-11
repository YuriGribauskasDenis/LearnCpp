#include <iostream>

using namespace std;

struct Vector2
{
    float x, y;
};

struct Vector4
{
    float x, y, z, w;
    // cretates new object
    // Vector2 getA()  { return Vector2(x,y); }
    // puning
    Vector2& getA()  { return *(Vector2*)&x; }
};

void PrintVector2(const Vector2& vector)
{
    cout<<vector.x<<", "<<vector.y<<endl;
}

int main()
{
    struct Union
    {
        union
        {
            float a;
            //int b;
            float b;
        };
    };
    
    Union u;
    u.a = 0.2f;
    cout<<u.a<<", "<<u.b<<endl;
    
    return 0;
}
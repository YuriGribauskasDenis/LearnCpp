#include <iostream>
#include <algorithm>


class vertex
{
public:
    const float getX() const {
        return _x;
    }
    const float getY() const {
        return _y;
    }
    const float getZ() const {
        return _z;
    }
    vertex() : _x{0}, _y{0}, _z{0} {}
    vertex( float x, float y, float z ) : _x{x}, _y{y}, _z{z} {}
    operator float*() {
        std::cout << "operator float*" << std::endl;
        return &_x;
    }
    operator const float*() const {
        std::cout << "operator const float*" << std::endl;
        return &_x;
    }
private:
    float _x;
    float _y;
    float _z;
};

int main() 
{
    vertex v( 1, 3, 2 );
    const float* max = std::max_element( v + 0, v + 3 );
    std::cout << *max << std::endl;
    std::cout << "//-------------------------//" << std::endl;
    float* a1 = v;
    // assert(*a1 == 1);
    const float* a2 = v;
    const float* const a3 = v;
    float* const a4 = v;

    return 0;
}
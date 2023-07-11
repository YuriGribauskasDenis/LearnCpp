
#include <iostream>

using namespace std;

struct X
{
    short s; /* 2 bytes */
             /* 2 padding bytes */
    int   i; /* 4 bytes */
    char  c; /* 1 byte */
             /* 3 padding bytes */
};

struct Y
{
    int   i; /* 4 bytes */
    char  c; /* 1 byte */
             /* 1 padding byte */
    short s; /* 2 bytes */
};

struct Z
{
    int   i; /* 4 bytes */
    short s; /* 2 bytes */
    char  c; /* 1 byte */
             /* 1 padding byte */
};

int main()
{
    const int sizeX = sizeof(struct X); /* = 12 */
    cout << sizeX << endl;
    const int sizeY = sizeof(struct Y); /* = 8 */
    cout << sizeX << endl;
    const int sizeZ = sizeof(struct Z); /* = 8 */
    cout << sizeX << endl;



    return 0;
}
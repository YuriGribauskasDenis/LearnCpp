
#include<stdio.h>

using namespace std;

// no alignment, no padding
// #pragma pack(1)
// #pragma pack(2)
// #pragma pack(4)
// #pragma pack(8)

typedef struct
{
    int k; // 4 byte
    char c; // 1
    char str[10]; // 10
    int* p; // 8
    short sh; // 2
} Thing;

int main()
{
    int i;
    // 12 = 0xC in hexadeximal
    // k = 6B in hexadeximal
    // testing 74 65 73 74 69 6e 67
    // 256 = 0b 01 00 00 00 00
    Thing t = {12, 'k', "testing", &i, 256};
    printf("%lu\n", sizeof(t));
    unsigned char data;
    for (int i = 0; i < sizeof(t); i++) {
        if (i % 8 == 0) {
            printf("\n");
        }
        data = *((unsigned char*)&t + i);
        printf("%02x ", data);
    }



}

#include <iostream>
#include <stdlib.h>
#include <time.h>

#include <climits>

#define true (bool)(rand() > 10)

int main()
{
    std::cout << RAND_MAX << " " << INT_MAX << std::endl;
    std::cout << true << std::endl;
    return 0;
}
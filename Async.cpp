
#include <iostream>
#include <chrono>
#include <thread>
#include <algorithm>
#include <future>

typedef long int ull;

ull FindOddNumbersSum(ull Start, ull End)
{
    ull Odd = 0;
    for ( ull i = Start; i <= End; i++)
    {
        if ( i & 1 )
        {
            Odd += i;
        }
    }
    return Odd;
}

int main()
{
    ull Start = 0;
    ull End = 1900000000;
    
    std::cout << "Thread created if policy is launch::async" << std::endl;
    std::future<ull> OddSum = std::async(std::launch::deferred, FindOddNumbersSum, Start, End);
    
    std::cout << "Waiting" << std::endl;
    std::cout << "Result " << OddSum.get() << std::endl;
    std::cout << "End" << std::endl;

    return 0;
}
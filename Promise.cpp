
#include <iostream>
#include <chrono>
#include <thread>
#include <algorithm>
#include <future>

typedef long int ull;

void FindOddNumbersSum(std::promise<ull>&& OddSumPromise, ull Start, ull End)
{
    ull Odd = 0;
    for ( ull i = Start; i <= End; i++)
    {
        if ( i & 1 )
        {
            Odd += i;
        }
    }
    OddSumPromise.set_value(Odd);
}

int main()
{
    ull Start = 0;
    ull End = 1900000000;
    
    std::promise<ull> PromiseOdd;
    std::future<ull> FutureOdd;
    FutureOdd = PromiseOdd.get_future();
    
    std::cout << "Start" << std::endl;
    
    std::thread thread01(FindOddNumbersSum, std::move(PromiseOdd), Start, End);
    
    std::cout << "Waiting" << std::endl;
    std::cout << "Result " << FutureOdd.get() << std::endl;
    std::cout << "End" << std::endl;
    
    thread01.join();
    std::cout << "Join" << std::endl;

    return 0;
}
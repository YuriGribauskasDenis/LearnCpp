
#include <iostream>
#include <thread>
#include <chrono>


void run(int count)
{
    while ( count-- > 0)
    {
        std::cout << "C++ Threading" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main()
{
    std::thread t1(run, 5);
    std::cout << "working" << std::endl;
    t1.join();
    // double join = program termination
    // t1.join();
    std::cout << "End" << std::endl;
    
    // check if joinable
    if (t1.joinable())
    {
        t1.join();
        std::cout << "End 01" << std::endl;
    }

    return 0;
}
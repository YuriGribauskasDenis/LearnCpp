
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
    // not waiting the thread to end and pocede
    // so main returns faster than thread ends
    t1.detach();
    // do not detach twice
    // use joinable
    // do join or detach, if not destructor will terminate parent thread - main program
    std::cout << "End" << std::endl;
    

    return 0;
}
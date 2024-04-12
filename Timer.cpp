
#include <iostream>
#include <chrono>
#include <thread>


namespace TimeLiteral = std::literals::chrono_literals;
using TimePointHighRes = std::chrono::time_point<std::chrono::high_resolution_clock>;
using TimePointSteady = std::chrono::time_point<std::chrono::steady_clock>;
using Duration = std::chrono::duration<float>;

class Timer
{
public:
    Timer()
    {
        _Start = std::chrono::steady_clock::now();
    }
    ~Timer()
    {
        _End = std::chrono::steady_clock::now();
        _Duration = _End - _Start;
        // std::chrono::system_clock::duration mcs = std::chrono::duration_cast<std::chrono::microseconds> (_Duration);
        // auto mcs = std::chrono::duration_cast<std::chrono::microseconds> (_Duration);
        std::chrono::duration<long, std::micro> mcs = std::chrono::duration_cast<std::chrono::microseconds> (_Duration);
        std::cout << mcs.count() << " mcs" << std::endl;
    }
private:
    TimePointSteady _Start;
    TimePointSteady _End;
    Duration _Duration;
};

int main()
{
    TimePointHighRes start = std::chrono::high_resolution_clock::now();
    
    constexpr std::chrono::duration<long double> AroundOneSec = TimeLiteral::operator""s(1.2);
    
    {
        Timer T;
        std::this_thread::sleep_for(AroundOneSec);
    }
    
    TimePointHighRes end = std::chrono::high_resolution_clock::now();
    
    std::chrono::duration<float> duration = end - start;
    
    std::cout << duration.count() << " s" << std::endl;

    return 0;
}

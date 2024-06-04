
#include <iostream>
#include <map>
#include <thread>
#include <atomic>
#include <string>
#include <chrono>


using namespace std::chrono_literals;
typedef std::map<std::string, int> MyMap;

class GlobalWarming
{
public:
    GlobalWarming() {}
    // ~GlobalWarming()
    // {
    //     if (_ThreadClimateWarming.joinable())
    //     {
    //         _TerminateClimateWarming = false;
    //         _ThreadClimateWarming.join();
    //     }
    //     if (_ThreadClimateCooling.joinable())
    //     {
    //         _TerminateClimateCooling = false;
    //         _ThreadClimateCooling.join();
    //     }
    // }
    void InitNode(MyMap ForecastMap)
    {
        _ForecastMap = ForecastMap;
        //------------//
        _TerminateClimateWarming = true;
        _ThreadClimateWarmingRunning = false;
        //------------//
        _TerminateClimateCooling = true;
        _ThreadClimateCoolingRunning = false;
    }
    void RefreshWarmingForecast(const std::string& comment)
    {
        constexpr auto dilay{ 2000ms };
        while(!_TerminateClimateWarming)
        {
            std::cout << "Warming. " << comment << std::endl;
            std::map<std::string, int>::iterator it = _ForecastMap.begin();
            for (it; it != _ForecastMap.end(); it++)
            {
                it->second += 1;
                std::cout << it->first << " - " << it->second << std::endl;
            }
            std::cout << "//------------//" << std::endl;
            std::this_thread::sleep_for(dilay);
        }
    }
    int RefreshCoolingForecast(const std::string& comment)
    {
        constexpr auto dilay{ 2000ms };
        while(_ThreadClimateCoolingRunning) {
            std::cout << "Cooling. " << comment << std::endl;
            std::map<std::string, int>::iterator it = _ForecastMap.begin();
            for (it; it != _ForecastMap.end(); it++)
            {
                it->second -= 1;
                std::cout << it->first << " - " << it->second << std::endl;
            }
            std::cout << "//------------//" << std::endl;
            std::this_thread::sleep_for(dilay);
        }
        return 0;
    }
    const MyMap& GetForeCast() const { return _ForecastMap; }
    void StartClimateWarming()
    {
        if (!_ThreadClimateWarmingRunning)
        {
            _ThreadClimateWarmingRunning = true;
            _TerminateClimateWarming = false;
            _ThreadClimateWarming = std::thread(&GlobalWarming::RefreshWarmingForecast, this, ""); // this == GlobalWarming()
        }
    }
    void StopClimateWarming()
    {
        _TerminateClimateWarming = true;
        if (_ThreadClimateWarmingRunning)
        {
            _ThreadClimateWarmingRunning = false;
            // _ThreadClimateWarming.detach();
            _ThreadClimateWarming.join();
        }
    }
    void StartClimateCooling()
    {
        if (!_ThreadClimateCoolingRunning)
        {
            _ThreadClimateCoolingRunning = true;
            _TerminateClimateCooling = false;
            _ThreadClimateCooling = std::thread(&GlobalWarming::RefreshCoolingForecast, this, ""); // this == GlobalWarming()
        }
    }
    void StopClimateCooling()
    {
        _TerminateClimateCooling = true;
        if (_ThreadClimateCoolingRunning)
        {
            _ThreadClimateCoolingRunning = false;
            // _ThreadClimateCooling.detach();
            _ThreadClimateCooling.join();
        }
    }
private:
    MyMap _ForecastMap;
    //------------//
    std::atomic<bool> _TerminateClimateWarming;
    std::atomic<bool> _ThreadClimateWarmingRunning;
    std::thread _ThreadClimateWarming;
    //------------//
    std::atomic<bool> _TerminateClimateCooling;
    std::atomic<bool> _ThreadClimateCoolingRunning;
    std::thread _ThreadClimateCooling;
    //------------//
};


int main()
{
    MyMap forecastMap = {
        {"New York", 15},
        {"Mumbai", 20},
        {"Berlin", 18}
    };

    GlobalWarming gw;
    gw.InitNode(forecastMap);

    gw.StartClimateWarming();
    std::this_thread::sleep_for(6s);
    gw.StopClimateWarming();

    std::cout << "//==================//" << std::endl;
    std::cout << "//====INTERMEZZO====//" << std::endl;
    std::cout << "//==================//" << std::endl;
    
    gw.StartClimateCooling();
    std::this_thread::sleep_for(std::chrono::seconds(4));
    gw.StopClimateCooling();
    
    std::cout << "//==================//" << std::endl;
    MyMap checkForecast = gw.GetForeCast();
    for (const auto& item : checkForecast) {
        std::cout << item.first << " - " << item.second << std::endl;
    }
    std::cout << "//==================//" << std::endl;
    
    return 0;
}
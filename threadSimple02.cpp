
#include <iostream>
#include <map>
#include <thread>
#include <string>
#include <chrono>


using namespace std::chrono_literals;
typedef std::map<std::string, int> MyMap;


void RefreshForecast(MyMap forecastMap) {
// void RefreshForecast(MyMap& forecastMap) {
    constexpr auto dilay{ 2000ms };
    while(true) {
        for (auto& item : forecastMap) {
            item.second++;
            std::cout << item.first << " - " << item.second << std::endl;
        }
        // std::map<std::string, int>::iterator it = forecastMap.begin();
        // for (it; it != forecastMap.end(); it++) {
        //     it->second++;
        //     std::cout << it->first << " - " << it->second << std::endl;
        // }
        std::cout << "//------------//" << std::endl;
        std::this_thread::sleep_for(dilay);
    }
}


int main()
{
    MyMap forecastMap = {
        {"New York", 15},
        {"Mumbai", 20},
        {"Berlin", 18}
    };

    std::thread bgWorker(RefreshForecast, forecastMap);
    std::this_thread::sleep_for(6s);
    
    bgWorker.detach();
    
    std::cout << "//==================//" << std::endl;
    for (const auto& item : forecastMap) {
        std::cout << item.first << " - " << item.second << std::endl;
    }
    std::cout << "//==================//" << std::endl;
    
    return 0;
}
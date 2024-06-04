
#include <iostream>
#include <thread>


void function1(int duration, char symbol) {
    for (int i = 0; i < duration; i++) {
        std::cout << symbol;
    }
}

void function2(int duration) {
    for (int i = 0; i < duration; i++) {
        std::cout << "-";
    }
}

int main()
{
    int du1 = 200;
    int du2 = 200;
    
    std::thread worker1(function1, du1, '+');
    std::thread worker2(function2, du2);
    
    worker1.join();
    worker2.join();
    
    std::cout << std::endl;
    
    return 0;
}
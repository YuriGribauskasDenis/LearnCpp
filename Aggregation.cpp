
#include <iostream>

class Engine
{
public:
    Engine() { std::cout << "E+" << std::endl; }
    ~Engine() { std::cout << "E-" << std::endl; }
};

class Car
{
public:
    Car() { std::cout << "C+" << std::endl; }
    Car( Engine* const e ) : engine{e}
    {
        std::cout << "C+" << std::endl;
    }
    ~Car()
    {
        // delete engine;
        std::cout << "C-" << std::endl;
    }
private:
    Engine* engine = nullptr;
};

int main()
{
    {
        Car c0;
    }
    std::cout << "/---------------/" << std::endl;
    {
        Engine e1;
        Car c1(&e1);
    }
    std::cout << "/---------------/" << std::endl;
    Engine e2;
    {
        Car c1(&e2);
    }
    std::cout << "/---------------/" << std::endl;

    return 0;
}

// C+
// C-
// /---------------/
// E+
// C+
// C-
// E-
// /---------------/
// E+
// C+
// C-
// /---------------/
// E-

#include <iostream>
#include <memory>

class Entity
{
public:
    Entity() {std::cout<<"E+"<<std::endl;}
    ~Entity() {std::cout<<"E-"<<std::endl;}
    void Print() {std::cout<<"E functionality"<<std::endl;}
};

int main()
{
    {
        std::unique_ptr<Entity> u_e = std::make_unique<Entity>();
        u_e->Print();
    }
    
    std::shared_ptr<Entity> s_e0;
    std::weak_ptr<Entity> w_e;
    {
        std::shared_ptr<Entity> s_e = std::make_shared<Entity>();
        s_e0 = s_e;
        w_e = s_e;
        s_e0->Print();
    }
    s_e0->Print();
    // if (std::shared_ptr<Entity> s_1 = w_e.lock()) {
    //     std::shared_ptr<Entity> s_1 = w_e.lock();
    if(!w_e.expired()) {
        std::cout<<"WOW"<<std::endl;
        s_1->Print();
    } else {
        std::cout<<"NOO"<<std::endl;
    }

    return 0;
}
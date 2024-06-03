
#include <iostream>

class Action
{
public:
    virtual void action() = 0;
    virtual void name() = 0;
};

class Action1 : public Action
{
public:
    void action() override {
        std::cout << "BlobDetector in action" << std::endl;
    }
    void name() override {
        std::cout << "Blob" << std::endl;
    }
};

class Action2 : public Action
{
public:
    void action() override {
        std::cout << "YOLO results in action" << std::endl;
    }
    void name() override {
        std::cout << "YOLO" << std::endl;
    }
};

class Node
{
public:
    ~Node() {}
    void setAction(Action *a) {
        p_a = a;
        std::cout << "Functionality set to..." << std::endl;
        p_a->name();
        std::cout << std::endl;
    }
    void action() {
        if (nullptr != p_a) {
            p_a->action();
            std::cout << std::endl;
        }
    }
private:
    Action *p_a;
};


int main()
{
    Action1 a1;
    Action2 a2;
    Node o;
    o.setAction(&a1);
    o.action();

    o.setAction(&a2);
    o.action();

    return 0;
}
#include <iostream>
#include <string>

using namespace std;

class Printable
{
    // template
    // interface
    // just a class
    // unimplemented methods only
    // no instantiation
public:
    virtual string GetClassName() = 0;
};

class Entity : public Printable
{
public:
    virtual string GetName() {return "Entity";};
    string GetClassName() {return "Entity";};
};

//if entity is not inherited from Printable
class Player : public Entity //, Printable
{
public:
    Player(const string& name) : m_name{name} {}
    
    // required
    // keyword not required
    string GetName() override {return m_name;}
    string GetClassName() override {return "Player";};
private:
    string m_name;
};

void PrintName(Entity* entity)
{
    cout<<entity->GetName()<<endl;
    cout<<"------------------"<<endl;
}

class A : public Printable
{
public:
    string GetClassName() override {return "A";};
};

void Print(Printable* obj)
{
    // interface guarantird there is a GetClassName method
    cout<<obj->GetClassName()<<endl;
    cout<<"------------------"<<endl;
}

int main()
{
    Entity* entity = new Entity();
    cout<<entity->GetName()<<endl;
    cout<<"------------------"<<endl;
    Player* player = new Player("Denis");
    cout<<player->GetName()<<endl;
    cout<<"------------------"<<endl;
    PrintName(player);
    Print(entity);
    Print(player);
    
    // memory leak
    Print(new A());
    return 0;
}

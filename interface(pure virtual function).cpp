#include <iostream>
#include <string>

using namespace std;

class Entity
{
public:
    // template
    // interface
    // unimplemented methods only
    // no instantiation
    virtual string GetName() = 0;
};

class Player : public Entity
{
public:
    Player(const string& name) : m_name{name} {}
    
    // required
    // keyword not required
    string GetName() override {return m_name;}
private:
    string m_name;
};

void PrintName(Entity* entity)
{
    cout<<entity->GetName()<<endl;
    cout<<"------------------"<<endl;
}

int main()
{
    Entity* poly = new Player("Denis");
    cout<<poly->GetName()<<endl;
    cout<<"------------------"<<endl;
    Player* player = new Player("YuriiDenis");
    cout<<player->GetName()<<endl;
    cout<<"------------------"<<endl;
    PrintName(poly);
    return 0;
}

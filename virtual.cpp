#include <iostream>
#include <string>

using namespace std;

class Entity
{
public:
    // dynamic dispatch
    // needs memory M O()
    // v table (maping off all virtual overriden functions)
    // override
    // every time we call a function we run through table
    // T O()
    virtual string GetName() {return "Entity";}
    // with a bode override is optional
};

class Player : public Entity
{
public:
    Player(const string& name) : m_name{name} {}
    
    // not required
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
    Entity* entity = new Entity();
    cout<<entity->GetName()<<endl;
    cout<<"------------------"<<endl;
    Player* player = new Player("Denis");
    cout<<player->GetName()<<endl;
    cout<<"------------------"<<endl;
    Entity* p = new Player("Denis2");
    cout<<p->GetName()<<endl;
    cout<<"------------------"<<endl;
    Entity* e = p;
    cout<<e->GetName()<<endl;
    cout<<"------------------"<<endl;
    Entity* poly = new Player("YuriiDenis");
    cout<<poly->GetName()<<endl;
    cout<<"------------------"<<endl;
    PrintName(poly);
    return 0;
}

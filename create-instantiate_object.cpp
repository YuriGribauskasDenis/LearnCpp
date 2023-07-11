#include <iostream>
#include <string>

using namespace std;

//using String = string;
typedef string String;

class Entity
{
private:
    String m_name;
public:
    Entity() : m_name{"Unknown"} {}
    Entity(const String& nam) : m_name{nam} {}
    const String GetName() const {return m_name;}
};

int main() 
{
    // default constructor
    // as long as we have it it initializizes objext
    Entity entity;
    cout << entity.GetName() << endl;
    
    Entity entity2("Denis");
    // fastest and most managed way to instantiate object
    Entity entity3 = Entity("Yuri");
    
    // we can't do it if we want it to live outside scope
    Entity* pe;
    {
        Entity entity0("Dennis");
        pe = &entity0;
        cout << pe->GetName() << endl;
    }
    
    // big objest or I want to manually control the life of object
    // on heap - longer and we need to free memory
    Entity* pe2;
    {
        Entity* entity02 = new Entity("Dennis2");
        pe2 = entity02;
        cout << pe2->GetName() << endl;
        // in this case pe2 will point to mem outside freelist
        //delete entity02;
    }
    cout << pe2->GetName() << endl;
    // because it points to new allocated memory
    delete pe2;
    
    
    
    return 0; 
}
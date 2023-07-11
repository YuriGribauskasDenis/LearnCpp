#include <iostream>
using namespace std;

class Entity
{
public:
    Entity()
    {
        cout << "Entity Created" << endl;
    }
    ~Entity()
    {
        cout << "Entity Destroyed" << endl;
    }
};

// Scoped pointer
// class wrapper over pointer
// upon constructon heap allocates pointer
// upon destruction heap allocates the pointer
// automate new dwlwtw

class ScopedPtr
{
private:
    Entity* m_Ptr;
public:
    ScopedPtr (Entity* ptr)
        : m_Ptr{ptr} {}
    ~ScopedPtr ()
    {
        delete m_Ptr;
    }
};

int main()
{
    {
        // this will die
        // Entity* e = new Entity();
        // instead
        ScopedPtr e = new Entity(); // implicit conversion
        // or default constructor
        // ScopedPtr e(new Entity());
        
        // scoper pointer gets deleted automatically within class destructor
        // previous version - no
    }
}
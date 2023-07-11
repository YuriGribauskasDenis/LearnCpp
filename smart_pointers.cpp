#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Entity
{
public:
    Entity(){cout<<"Entity built"<<endl;}
    ~Entity(){cout<<"Entity destroyed"<<endl;}
    
    void Print() {}
};

int main()
{
    {
        // ptr constructor is explicit. next not possible
        // unique_ptr<Entity> entity = new Entity();
        // i have to call it implicitely
        // don't. cause of exception safety
        // unique_ptr<Entity> entity(new Entity());
        // preferred way. due to exceptions safety
        // also avoid new keyword at all
        unique_ptr<Entity> entity = make_unique<Entity>();
        // copy constructor and copy assignment are deleted
        // unique_ptr<Entity> e0 = entity;
        entity->Print();
    }
    //dies here
    cout<<"------------------"<<endl;
    {
        shared_ptr<Entity> e0;
        {
            // reference counting
            // int. deletes only when reaches zero
            shared_ptr<Entity> entity = make_shared<Entity>();
            // don't. cause makee_shared allocates new entity on it's own
            // and you do that explicitaly = 2 allocations
            // and than controll block when make does it together
            // shared_ptr<Entity> entity(new Entity());
            shared_ptr<Entity> sharedEntity = make_shared<Entity>();
            // shared_ptr<Entity> e1(e0);
            // shared_ptr<Entity>(e0)->Print();
            e0 = sharedEntity;
            e0->Print();
        }
    }
    cout<<"------------------"<<endl;
    {
        shared_ptr<Entity> e0;
        {
            shared_ptr<Entity> sharedEntity = make_shared<Entity>();
            // does not increase refcount
            weak_ptr<Entity> weakEntity = sharedEntity;
            e0 = sharedEntity;
            e0->Print();
        }
    }
    cout<<"------------------"<<endl;
    {
        weak_ptr<Entity> e0;
        {
            shared_ptr<Entity> sharedEntity = make_shared<Entity>();
            e0 = sharedEntity;
        }
        // i can ask if it is alive but code won't keep it alive
        // e0->Print();
    }
}

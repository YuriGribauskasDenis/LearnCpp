
#include <iostream>
#include <string>

using namespace std;

class Entity
{
public:
    Entity() = default;
    Entity(Entity* const parent, const string& name) : m_parent{parent}, m_name{name} {}
    const string& GetName() const {return m_name;}
    void Print() const { cout << "Entity" << endl; }
public:
    Entity* m_parent;;
    string m_name;
};

struct EntityData
{
    Entity* m_parent;
    string m_name;
};
const string& ED_GetName(const EntityData* self) {
    //nullptr == self
    
    // uint64_t offset = offset(EntityData, m_name);
    
    return self->m_name;
}
void ED_Print(EntityData* self) { cout << "Entity" << endl; }

#define myoffsetof(s, m) ((size_t)&(((s*)0)->m))

int main()
{
    void* value = nullptr; // NULL
    cout << value << endl;
    // int n = NULL;
    // cout << n << endl;
    // int 0 is not a valid address
    //printf("%d\n", *value);
    
    uint64_t offset = offsetof(EntityData, m_name);
    cout << "Offset for name " << offset << endl;
    cout << "Offset for name " << ((size_t)&(((EntityData*)0)->m_name)) << endl;
    cout << "Offset for name " << myoffsetof(EntityData, m_name) << endl;
    
    //Entity* e = new Entity(nullptr, "Fiona");
    Entity* e = new Entity();
    cout << "Name "<< e->GetName() << endl;
    e->Print();
    // build error presumably
    // uninitialized variable
    // Entity* e0;
    Entity* e0 = nullptr;
    // access violation presumably
    // this was 0x8
    cout << "Name "<< e0->GetName() << endl;
    e0->Print();
    
    return 0;
}
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
    int a = 2;
    int* b = new int;
    int* b2 = new int[50]; // 200 bytes
    
    // Entity* e = new Entity; // default constructor
    
    // not only allocates memory but calls the constructor
    Entity* e = new Entity();
    // not calls the constructor
    // do not do it
    Entity* e2 = (Entity*) malloc(sizeof(Entity()));
    
    delete b;
    delete[] b2;
    delete e;
    free(e2);
    
    return 0; 
}
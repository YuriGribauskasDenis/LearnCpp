#include <iostream> 
# include <string>

using namespace std; 

class Entity
{
private:
    int *m_p, m_x, m_y;
    // so const can modify it
    mutable int var;
public:
    int GetX() const // i shall not change class data
    {
        var = 2;
        return m_x;
    }
    int GetX()
    {
        return m_x;
    }
    void SetX(int x)
    {
        m_x = x;
    }
    const int* const GetP() const
    {
        return m_p;
    }
};

// (Entity e) argument will copy object
void PrintEntity(const Entity& e)
{
    // we can modify (const Entit* e) argument
    // e = nullptr;
    // we cannot modify conyent of e argument
    // with (const Entit& e) argument we have same case
    // we also cannot reassign it to smth else
    // with e = Entity() we try to change this object not some other
    // there is no separation between pointer and content
    // with reference you are the content, there is no dereferencing
    // const in function does not allow to modify argument (const Entit& e)
    // cause it is a reference
    // without const after function i am not allowed to have that argument
    // because GetX function does not guarantee it is not changing Entity object
    // which is not allowed by argument
    // that is why we have two versions of functions
    // here we use const version
    cout<<e.GetX()<<endl;
}

int main()
{
    Entity e;

    return 0;
} 
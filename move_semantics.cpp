#include <iostream> 

#define LOG(x) std::cout << x << std::endl 

class String 
{
public: 
    //String() = default;
    String(const char* string)
    {
        LOG("Created");
        m_Size = strlen(string);
        m_Data = new char[m_Size];
        memcpy(m_Data, string, m_Size);
    }

    String(const String& other)
    {
        LOG("Copied");
        m_Size = other.m_Size;
        m_Data = new char[m_Size];
        memcpy(m_Data, other.m_Data, m_Size);
    }

    String(String&& other)
    {
        LOG("Moved");
        m_Size = other.m_Size;
        m_Data = other.m_Data;
        other.m_Size = 0;
        other.m_Data = nullptr;
    }

    ~String()
    {
        LOG("Destroyed");
        delete m_Data;
    }

    void Print()
    {
        for (int i = 0; i < m_Size; i++)
        {
            std::cout << m_Data[i];
        }
        std::cout << std::endl;
    }

private:
    char* m_Data;
    //uint32_t m_Size;
    int m_Size;
}; 

class Entity
{
public:
    Entity(const String& name) :
        m_Name(name)
    {}

    Entity(String&& name) :
        //m_Name((String&&)name)
        m_Name(std::move(name))
    {}

    void PrintName()
    {
        m_Name.Print();
    } 

private:
    String m_Name;
}; 

int main()
{
    //String s("Yura");
    // Entity entity(String("Denis"));
    // entity.PrintName();
    Entity entity2("Dennis");
    entity2.PrintName();
} 
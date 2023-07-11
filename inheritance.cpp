#include <iostream>
#include <string>

using namespace std;

class Entity
{
public:
    // 2x4bytes
    float m_x, m_y;
    void Move(const float& x, const float& y)
    {
        m_x += x;
        m_y += y;
    }
};

class Player : public Entity
{
public:
    // 4bytes on 32bit app
    // 8bytes on 64bit app
    const char* m_name;
    void PrintName(){cout<<m_name<<endl;}
};

int main()
{
    cout<<sizeof(Entity)<<endl;
    cout<<sizeof(Player)<<endl;
    
    Player player;
    player.PrintName();
    player.m_x = 5;
    player.Move(5,5);
}

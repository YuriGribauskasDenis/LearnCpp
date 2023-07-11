#include <iostream>

using namespace std;

class Entity
{
public:
    // now this class has a v-table
    // it is polymorphic type and we can use d_c
    // dynamic cast can go to see v-table
    virtual void DoNothing() {}
};

class Player : public Entity
{
};

class Enemy : public Entity
{
};

int main()
{
    Player* player = new Player();
    // derived class has two types base and derives
    Entity* poly1 = player;
    // no. same reason
    // Player* p1 = poly1;
    Entity* poly2 = new Enemy();
    
    // cause we don't know
    // Player* p = poly2;
    // next initially may work
    Player* p1 = (Player*)poly2;
    // if we run common function - ok
    // if we do smth unique to player what enemy has not - problem
    
    
    Entity* actuallyPlayer = player;
    Entity* actuallyEnemy = new Enemy();
    Player* p2 = dynamic_cast<Player*>(actuallyPlayer);
    if (p2) cout<<"success"<<endl;
    else cout<<"failure"<<endl;
    Player* p3 = dynamic_cast<Player*>(actuallyEnemy);
    if (p3) cout<<"success"<<endl;
    else cout<<"failure"<<endl;
    // how does it know? it stores rtti about all our types
    // which is additional memory
    // and d_c does additional functionality
    // we can turn it off in VS and it will warning
    // cause it gives unpredictible behaviour
    // on execution - access violation
    if (dynamic_cast<Player*>(actuallyEnemy)) // typr check
    {
        // do stuff
        // cast again to use, so we do if(p3)
    }
    

    return 0;
}
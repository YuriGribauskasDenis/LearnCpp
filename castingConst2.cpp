
#include <iostream>

using namespace std;

class Pirate
{
public:
    Pirate(int b) : m_bootyRequest(b) {}
    void sail() const {
        cout << "Now we are in sea, Cap" << endl;
    }
    void pirateBusiness(int b) const {
        cout << "Now we robbed a ship, Cap" << endl;
        // (const_cast<Pirate*>(this))->m_bootyRequest = b;
        (const_cast<Pirate&>(*this)).m_bootyRequest = b;
    }
    const int& getRequested() const {
        return m_bootyRequest;
    }
private:
    int m_bootyRequest;
};

void goToSea(const Pirate& pir) {
    pir.sail();
    pir.pirateBusiness(8);
}

int main()
{
    Pirate pirate(2);
    cout << "Now I am in your team, Cap" << endl;
    cout << "I need " << pirate.getRequested() << " gold, Cap" << endl;
    goToSea(pirate);
    cout << "Now I need " << pirate.getRequested() << " gold, Cap" << endl;

    return 0;
}
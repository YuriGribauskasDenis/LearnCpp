 
#include <iostream>
#include <memory>

using namespace std;
 
class Box
{
public:
    Box() : m_x(0), m_y(0) {}
    Box(int x, int y) : m_x(x), m_y(y) {}
    const int& getX() const {
        return m_x;
    }
    const int& getY() const {
        return m_y;
    }
    void show() const {
        cout << getX() << " " << getY() << endl;
    }
private:
    int m_x, m_y;
};

void showP(const Box* b) {
    b->show();
}
void showR(const Box& b) {
    b.show();
}
void showU(unique_ptr<Box>& b) {
    b->show();
}
void showM(unique_ptr<Box> b) {
    b->show();
}

int main()
{
    unique_ptr<Box> b( new Box(20, 30) );
    unique_ptr<Box> b2( new Box(22, 32) );

    b->show();
    b.get()->show();
    cout << "-----------" << endl;
    showP(b.get());
    showP(b.operator->());
    showP(&*b);
    cout << "-----------" << endl;
    showR(*b.get());
    showR(*b);
    cout << "-----------" << endl;
    showU(b);
    cout << "-----------" << endl;
    showM(make_unique<Box>(55, 65));
    showM(unique_ptr<Box>(new Box(56, 66)));
    showM(unique_ptr<Box>(b.release()));
    showM(move(b2));
    cout << "-----------" << endl;
    if (b) {
        cout << b->getX() << " " << b->getY() << endl;
    } else {
        cout << "no more unique pointer" << endl;
    }
    b = unique_ptr<Box>(new Box(23, 33));
    if (b) {
        cout << b->getX() << " " << b->getY() << endl;
    } else {
        cout << "no more unique pointer" << endl;
    }
    
    
    
    
    return 0;
}
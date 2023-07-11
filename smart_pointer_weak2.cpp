
#include <iostream>
#include <memory>

using namespace std;

int main()
{
    shared_ptr<int> sharedP1 = make_shared<int>(100);
    // count does not grow
    weak_ptr<int> weakP1 = sharedP1;
    weak_ptr<int> weakP2(weakP1);
    
    // 1
    cout << sharedP1.use_count() << endl;

    shared_ptr<int> p_shared = make_shared<int>(100);
    weak_ptr<int>   p_weak(p_shared);
    
    // may be null if p_shared is deleted
    shared_ptr<int> p_shared_orig = p_weak.lock();

    return 0;
}
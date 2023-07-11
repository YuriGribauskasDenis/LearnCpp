#include <iostream> 
# include <string>

using namespace std; 

int main()
{
    const int MAX_AGE = 90;
    int* a = new int;
    *a = 2;
    cout<<*a<<endl;
    a = (int*)&MAX_AGE;
    cout<<*a<<endl;
    
    const int* a1 = new int;
    // can't change content, data at rhat memory
    //*a1 = 2;
    a1 = (int*)&MAX_AGE;
    cout<<*a1<<endl;

    int* const a2 = new int;
    *a2 = 2;
    // can't change reference
    // can't reassign the actual pointer itself
    //a2 = (int*)&MAX_AGE;
    
    const int* const a3 = new int;
    // *a3 = 2;
    // cout<<*a3<<endl;
    
    return 0;
} 
#include <iostream>

using namespace std;

int main()
{
    int* ptr;
    int n = 5;
    
    //ptr = (int*) malloc(n * sizeof(int));
    ptr = (int*) calloc(n, sizeof(int));
    
    if (ptr != 0) {
        for (size_t i = 0; i < n; i++) {
            ptr[i] = i + 1;
        }
        for (size_t i = 0; i < n; i++) {
            cout << ptr[i] << " ";
        }
        cout << endl;;
        
        free(ptr);
        ptr = 0;
    }
    
    cout << "The value of ptr is " << ptr << endl;
}
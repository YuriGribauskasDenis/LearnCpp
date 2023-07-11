#include <iostream>

using namespace std;

int main()
{
    int* ptr;
    int* ptr2;
    int i;
    int n = 5;

    ptr = (int*) calloc(n, sizeof(int));

    // if == NULL or 0 or nullptr
    if (ptr != 0) {
        for (i = 0; i < n; i++) {
            ptr[i] = i + 1;
        }
        for (i = 0; i < n; i++) {
            cout << ptr[i] << " ";
        }
        cout << endl;
  
        n = 10;
        ptr2 = (int*) realloc(ptr, n * sizeof(int));
        for (i = 5; i < n; i++) {
            ptr2[i] = i + 1;
        }

        for (i = 0; i < n; i++) {
            cout << ptr2[i] << " ";
        }
        cout << endl;
  
        free(ptr2);
        cout << "The value of ptr  is " << ptr << endl;
        cout << "The value of ptr2 is " << ptr2 << endl;
        ptr = 0;
        ptr2 = 0;
        cout << "The value of ptr  is " << ptr << endl;
        cout << "The value of ptr2 is " << ptr2 << endl;
    }
  
    return 0;
}
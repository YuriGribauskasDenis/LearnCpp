#include <iostream>
#include <cstring>

using namespace std;

class MyString 
{
public:
    explicit MyString(const char* st)
    {
        cout << "Created" << endl;
        this->m_Size = strlen(st);
        this->m_Data = new char[this->m_Size];
        memcpy(this->m_Data, st, this->m_Size);
    }

    explicit MyString(const MyString& other)
    {
        cout << "Copied" << endl;
        this->m_Size = other.m_Size;
        this->m_Data = new char[this->m_Size];
        memcpy(this->m_Data, other.m_Data, this->m_Size);
    }

    MyString(MyString&& other)
    {
        cout << "Moved" << endl;
        this->m_Size = other.m_Size;
        this->m_Data = other.m_Data;
        other.m_Size = 0;
        other.m_Data = nullptr;
    }

    ~MyString()
    {
        cout << "Destroyed" << endl;
        delete this->m_Data;
    }
    
    const char* const GetData() const {
        return m_Data;
    }
    
    const int GetSize() const {
        return m_Size;
    }

private:
    char* m_Data;
    int m_Size;
}; 

void print(const MyString& st) {
    cout << "PrintMyStr" << endl;
    for (int i = 0; i < st.GetSize(); i++) {
        cout << st.GetData()[i];
    }
    cout << endl;
}

void print (char *st) {
    cout << "PrintChar" << endl;
    int i = 0;
    while (st[i] != 0) {
        cout << st[i];
        i++;
    }
    cout << endl;
}

int main ()
{
    MyString astr("Denis");
    print(astr);
    
    print("Yura");
    //print(4);

    return 0;
}
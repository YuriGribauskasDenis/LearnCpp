struct Vector3
{
    float x, y, z;
    Vector3()
        : x{10.f}, y{11.f}, z{12.f} {}
};

int main()
{
    // stack (2MB) and heap are both in RAM

    int svalue = 5;
    // new calls malloc that calls platform specific method
    // program will maintain freelist, what memory is free and what is not
    // running through that list - slow
    int* hvalue = new int;
    *hvalue = 5;
    delete hvalue;
    
    // in a row backwards (last element pointer is first)
    // in a stack
    // when scope ends things pop from syack
    // pop - automatically free
    // any scope
    // the pointer to array begining just goes back
    // to where there was no array
    // 1 cpu instruction
    int sarray[5];
    // std::vector is on a heap
    // smart pointers call new for me
    // the whole separate thing
    // new and delete is heavy
    // malloc heavy
    int* harray = new int[5];
    // smart pointers delete themselves
    delete[] harray;
    
    // theoretically stack is hot
    // and on heap we can get cash misses
    // but in real life that almost never happens

    // better use stack unless you want it to live longer
    // or you load heavy thing (texture 15MB) it will not stick in stack

    Vector3 svector;
    // parenthesis are optional
    Vector3* hvector = new Vector3();
    // delete phisically
    delete hvector;
}
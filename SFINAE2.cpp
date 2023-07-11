#include <iostream> 
 
struct A 
{ 
}; 
 
struct B 
{ 
    B() { std::cout << "B+" << std::endl; } 
}; 
 
struct C 
{ 
    C(const A* Ptr) { std::cout << "C+ with " << Ptr << std::endl; } 
}; 
 
// https://groups.google.com/g/comp.std.c++/c/tWdhe_zKvK0/m/z_SqCzB3LQIJ 
 
namespace LowLevelHelpers 
{ 
    template<int> struct SHelper { }; 
    
    typedef char yes; 
    typedef short no; 
    
    template<typename Goal, typename Used> 
    yes Helper(int, SHelper<sizeof Goal(*(Used*)nullptr)>* = nullptr); 
    
    template<typename Goal, typename Used> 
    no Helper(...); 
 
    template<typename Goal, typename Used> 
    struct SConstructable 
    { 
        static bool const Answer = (sizeof Helper<Goal, Used>(0) == sizeof(yes)); 
    };

    template<typename Goal, typename Used>
    Goal Init(const Used* Ptr) 
    { 
        if constexpr ( SConstructable<Goal, const Used*>::Answer == true ) { 
            return Goal(Ptr); 
        } else { 
            return Goal(); 
        } 
    }
    
}
 
 
int main() 
{ 
    A a; // Database object type
    A* ptr = &a;
    B b = LowLevelHelpers::Init<B, A>(&a); // Function has different behavior based on B
    C c = LowLevelHelpers::Init<C, A>(ptr); // Function has different behavior based on C
     
    return 0; 
}
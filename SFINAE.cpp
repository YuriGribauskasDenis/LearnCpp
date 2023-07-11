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
 
namespace detail 
{ 
    template<int> struct D { }; 
    
    typedef char yes; 
    typedef short no; 
    
    template<typename T, typename U> 
    yes& f(int, D<sizeof T(*(U*)nullptr)>* = nullptr); 
    
    template<typename T, typename U> 
    no& f(...); 
} 
 
template<typename To, typename From> 
struct constructible 
{ 
    static bool const value = (sizeof detail::f<To, From>(0) == sizeof(detail::yes)); 
}; 
 
template<typename T0, typename T1> // T0 is the object we're reading, T1 is the object we're passing to it ( database object ) 
T0 Init(const T1* Ptr) 
{ 
    if constexpr ( constructible<T0, const T1*>::value == true ) { 
        return T0(Ptr); 
    } else { 
        return T0(); 
    } 
} 
 
int main() 
{ 
    A a; // Database object type 
    B b = Init<B, A>(&a); // Function has different behavior based on B 
    C c = Init<C, A>(&a); // Function has different behavior based on C 
     
    return 0; 
}
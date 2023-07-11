
#include <iostream>
#include <memory>

// make unique
// T - return type, Args - arguments' types
template <class T, class... Args>
// && adds referens before each in pack
auto make_unique(Args &&  ...args) {
    // forward - static_cast<decltype(arg)&&>(arg) to each in pack
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

template<class T>
void PrintSmart(const std::unique_ptr<T>& pT) {
    if (pT) {
        std::cout << *pT << std::endl;
    } else {
        std::cout << "smart pointer is no more" << std::endl;
    }
}

int main()
{
    auto y = make_unique<int>(42);
    std::cout << *y << std::endl;
    auto py = y.get();
    std::cout << *py << std::endl;
    PrintSmart(y);
    y.release();
    PrintSmart(y);

    return 0;
}
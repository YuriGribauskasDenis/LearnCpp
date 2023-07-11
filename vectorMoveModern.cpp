
#include <iostream>
#include <vector>
#include <string>

class Collection
{
public:
    Collection() {}
    void SetByValue (std::vector<std::string> vec) {
        m_vector = std::move(vec);
    }
    void SetByConstRefOrMove (const std::vector<std::string>& vec) {
        m_vector = vec;
    }
    void SetByConstRefOrMove (std::vector<std::string>&& vec) {
        m_vector = std::move(vec);
    }
    void Reset() {
        //std::swap(m_vector, std::vector<std::string>());
        // m_vector.swap(std::vector<std::string>());
        std::vector<std::string>().swap(m_vector);
    }
private:
    std::vector<std::string> m_vector;
};

int main()
{
    std::vector<std::string> lots_of_strings(1000000, "test string");
    Collection c;
    // Passing an l-value
    c.SetByValue(lots_of_strings);
    // Passing an r-value
    c.SetByValue(std::vector<std::string>(1000000, "test string"));
    // Passing an r-value reference
    c.SetByValue(std::move(lots_of_strings));
    
    lots_of_strings = std::vector<std::string>(1000000, "test string");
    // Reset vector because of move
    lots_of_strings = std::vector<std::string>(1000000, "test string");
    // l-value, calls const-ref overload
    c.SetByConstRefOrMove(lots_of_strings);
    // r-value, calls r-value-ref overload
    c.SetByConstRefOrMove(std::vector<std::string>(1000000, "test string"));
    // explicit move on l-value, calls r-value-ref overload
    c.SetByConstRefOrMove(std::move(lots_of_strings));

    return 0;
}
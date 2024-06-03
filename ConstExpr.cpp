
#include <type_traits>
#include <cmath>
#include <iostream>

namespace engine_math
{
    namespace custom_implementation
    {
        template<typename T>
        constexpr auto sqrt(const T& number) noexcept -> decltype(std::sqrt(number)) {
            // implementation details
            
            float start = 0.0f;
            float end = (float)number;
            float ans = -1.0f;
        
            while (start <= end) {
                int mid = start + (int)((end - start) / 2);
         
                if (mid * mid == number) {
                    ans = mid;
                    break;
                }
                if (mid * mid < number) {
                    start = mid + 1;
                    ans = mid;
                }
                else {
                    end = mid - 1;
                }
            }
            
            int precision = 4;
            float increment = 0.1;
            
            for (int i = 0; i < precision; i++) {
                while (ans * ans <= number) {
                    ans += increment;
                }
         
                ans = ans - increment;
                increment = increment / 10;
            }
            
            return ans;
        }
    }

    template<typename T>
    constexpr auto sqrt(const T& number) noexcept {
        if (std::is_constant_evaluated()) {
            return custom_implementation::sqrt(number);
        } else {
            return std::sqrt(number);
        }
    }
}

int main()
{
    constexpr float a = engine_math::sqrt(1764 + 1);
    std::cout << a << std::endl;
    std::cout << engine_math::sqrt(1764 + 1) << std::endl;

    return 0;
}
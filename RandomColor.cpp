
#include <random>
#include <iostream>


class Color
{
public:
    Color() : _R{0}, _G{0}, _B{0} {}
    Color(int r, int g, int b)
    {
        _R = _ColAvg(r);
        _G = _ColAvg(g);
        _B = _ColAvg(b);
    }
    void ColorPrint()
    {
        std::cout << _R << " " << _G << " " << _B << std::endl;
    }
private:
    int _ColAvg(int val)
    {
        if ( val < 0 || 255 < val)
        {
            val = 127;
        }
        return val;
    }
    int _R, _G, _B;
};

int main()
{
    std::random_device RD;
	std::mt19937 Gen(RD());
	std::uniform_int_distribution<int> Dis(100, 255);

    std::cout << Dis(Gen) << std::endl;
    
    std::cout << "/---------------------/" << std::endl;
    
    Color c01{-1, 12, 788};
    c01.ColorPrint();
    Color c02{Dis(Gen), Dis(Gen), Dis(Gen)};
    c02.ColorPrint();

    return 0;
}
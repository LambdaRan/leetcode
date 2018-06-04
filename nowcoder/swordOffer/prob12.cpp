
#include <iostream>
#include <math.h>


using namespace std;

/*
* Name: 数值的整数次方
* Description: 给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
*
*/
// 测试用例：底数和指数分别设为零
// 小数（float 和 double） 不能直接用符号（==）判断两个小数是否相等，
// 使用差的绝对值很小（0.0000001）就可认为他们相等
class Solution {
public:
    Solution()
        : g_InvalidInput(false)
    {}

    bool g_InvalidInput;
    double Power(double base, int exponent) {
        g_InvalidInput = false;
        if (_equal(base, 0.0) && exponent < 0)
        {
            g_InvalidInput = true;
            return 0.0;
        }

        unsigned int absExponent = static_cast<unsigned int>((exponent < 0 ? (-exponent) : exponent));
        double result = _powerWithUnsignedExponent(base, absExponent);
        if (exponent < 0)
            result = 1.0 / result;
        
        return result;
    }
    double Power1(double base, int exponent) {
        return pow(base, exponent);
    }
private: 
    double _powerWithUnsignedExponent(double base, unsigned int exponent)
    {
        if (exponent == 0) return 1.0;
        if (exponent == 1) return base;

        double result = _powerWithUnsignedExponent(base, exponent >> 1);
        result *= result;

        if (exponent & 0x01 == 1)
            result *= base;
        return result;
    }
    bool _equal(double num1, double num2)
    {
        if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
            return true;
        else 
            return false;
    }
};

int main() 
{
    Solution s;

    std::cout << "method 1: \n";
    std::cout << "power(0, 3): " << s.Power1(0, 3) << " --> " << s.Power(0, 3) << "\n";
    std::cout << "power(2, 11): " << s.Power1(2, 11) << " --> " << s.Power(2, 11) << "\n";
    std::cout << "power(3, 0): " << s.Power1(3, 0) << " --> " << s.Power(3, 0) << "\n";
    std::cout << "power(5, 5): " << s.Power1(5, 5) << " --> " << s.Power(5, 5) << "\n";
    std::cout << "power(7, -3): " << s.Power1(7, -3) << " --> " << s.Power(7, -3) << "\n";

    std::cout << std::endl;
    return 0;
}
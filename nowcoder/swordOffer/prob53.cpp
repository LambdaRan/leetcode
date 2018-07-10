
#include <iostream>
#include <algorithm>
#include <string>

#include <string.h>
#include <ctype.h>

using namespace std;

/*
* Name: 表示数值的字符串
* Description: 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
* 例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 
* 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
*
*/
class Solution {
public:
    bool isNumeric(const char* string)
    {
        if (string == NULL) return false;

        size_t strSize = ::strlen(string);
        size_t cur = 0;
        if (string[0] == '-' || string[0] == '+')
            ++cur;

        bool dot = false;
        bool hasE = false;
        while (cur < strSize)
        {
            if (::isdigit(string[cur]))
            {
                ++cur;
                continue;
            }
            else if (string[cur] == '.')
            {
                if (dot || hasE) return false;
                dot = true;
            }
            else if (string[cur] == 'e' || string[cur] == 'E')
            {
                if (hasE) return false;
                hasE = true;
                if (cur+1 >= strSize) return false;
                if (string[cur+1] == '-' || string[cur+1] == '+')
                    ++cur;
            }
            else  
            {
                return false;
            }
            ++cur;
        }
        return true;
    }
};

std::string boolToString(bool input) {
    return input ? "true" : "false";
}

int main() 
{
    Solution s;

    std::cout << "method 1: \n";
    std::cout << "isNumeric(+100): true <--> " << boolToString(s.isNumeric("+100")) << "\n";
    std::cout << "isNumeric(5e2): true <--> " << boolToString(s.isNumeric("5e2")) << "\n";
    std::cout << "isNumeric(-123): true <--> " << boolToString(s.isNumeric("-123")) << "\n";
    std::cout << "isNumeric(3.1416): true <--> " << boolToString(s.isNumeric("3.1416")) << "\n";
    std::cout << "isNumeric(-1E-16): true <--> " << boolToString(s.isNumeric("-1E-16")) << "\n";
    std::cout << "isNumeric(12e): false <--> " << boolToString(s.isNumeric("12e")) << "\n";
    std::cout << "isNumeric(1a3.14): false <--> " << boolToString(s.isNumeric("1a3.14")) << "\n";
    std::cout << "isNumeric(1.2.3): false <--> " << boolToString(s.isNumeric("1.2.3")) << "\n";
    std::cout << "isNumeric(+-5): false <--> " << boolToString(s.isNumeric("+-5")) << "\n";
    std::cout << "isNumeric(12e+4.3): false <--> " << boolToString(s.isNumeric("12e+4.3")) << "\n";
    std::cout << std::endl;
    return 0;
}

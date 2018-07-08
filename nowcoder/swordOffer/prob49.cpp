
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#include <cctype>
#include <stdio.h>

using namespace std;

/*
* Name: 把字符串转换成整数
* Description: 将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 
* 数值为0或者字符串不是一个合法的数值则返回0
* 输入描述:
*   输入一个字符串,包括数字字母符号,可以为空
* 输出描述:
*   如果是合法的数值表达则返回该数字，否则返回0
* 示例1
* 输入
* +2147483647
*     1a33
* 输出
* 2147483647
*     0
*
*/
class Solution {
public:
    int StrToInt(string str) {
        if (str.empty()) return 0;
        const int INT_MAX = 2147483647;
        const int INT_MIN = -2147483648;
        int index = 0;
        int c;
        int neg = 0;
        int ret = 0;
        do { /* 清除开头的空格 */
            c = str[index++];
        } while(std::isspace(c));
        /* 判断符号 */
        if (c == '-') 
        {
            neg = 1;
            c = str[index++];
        } else {
            neg = 0;
            if (c == '+')
                c = str[index++];
        }
        for ( ; std::isdigit(c); c = str[index++]) 
        {
            int digit = c - '0';
            if (neg) {
                if (-ret < (INT_MIN + digit)/10)
                return INT_MIN;
            } else {
                if (ret > (INT_MAX - digit)/10)
                return INT_MAX;
            }

            ret = ret * 10 + digit;
        }
        if (index < static_cast<int>(str.size()))
            return 0;
        return neg ? -ret : ret;
    }
};

int main() 
{
    Solution s;

    printf("\"%s\" = %d\n", "123", s.StrToInt("123"));
    printf("\"%s\" = %d\n", "   123", s.StrToInt("    123"));
    printf("\"%s\" = %d\n", "+123", s.StrToInt("+123"));
    printf("\"%s\" = %d\n", " -123", s.StrToInt(" -123"));
    printf("\"%s\" = %d\n", "123ABC", s.StrToInt("123ABC"));
    printf("\"%s\" = %d\n", " abc123ABC", s.StrToInt(" abc123ABC"));
    printf("\"%s\" = %d\n", "2147483647", s.StrToInt("2147483647"));
    printf("\"%s\" = %d\n", "-2147483648", s.StrToInt("-2147483648"));
    printf("\"%s\" = %d\n", "2147483648", s.StrToInt("2147483648"));
    printf("\"%s\" = %d\n", "-2147483649", s.StrToInt("-2147483649"));

    std::cout << std::endl;
    return 0;
}
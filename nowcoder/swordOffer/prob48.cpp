
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

/*
* Name: 不用加减乘除做加法
* Description: 写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
*
*/
class Solution {
public:
    int Add(int num1, int num2)
    {
        while (num2 != 0) // 进位值为0
        {
            // 不考虑进位，相加结果和异或结果一样
            // 5-101，7-111 第一步：相加各位的值，不算进位，得到010，
            // 二进制每位相加就相当于各位做异或操作，101^111
            int temp = num1^num2;
            // 第二步：计算进位值，得到1010，相当于各位做与操作得到101，再向左移一位得到1010，(101&111)<<1
            num2 = (num1&num2)<<1;
            num1 = temp;
        }
        return num1;
    }
};

int main() 
{
    Solution s;

    std::cout << "method 1: \n";

    std::cout << std::endl;
    return 0;
}

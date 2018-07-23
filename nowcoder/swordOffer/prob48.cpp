
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
        while (num2 != 0)
        {
            // 不考虑进位，相加结果和异或结果一样
            int temp = num1^num2;
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

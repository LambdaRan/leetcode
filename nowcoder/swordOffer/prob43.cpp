
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

/*
* Name: 左旋转字符串
* Description: 汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，
* 就是用字符串模拟这个指令的运算结果。对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
* 例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！
*
*/
class Solution {
public:
    // 正规做法 原理：YX = (X`T Y`T)`T
    string LeftRotateString(string str, int n) {
        if (n == 0) return str;
        if (str.size() <= 1) return str;

        int moveBit = n % str.size();

        std::reverse(str.begin(), std::next(str.begin(), moveBit));
        std::reverse(std::next(str.begin(), moveBit), str.end());
        std::reverse(str.begin(), str.end());
        return str;
    }
    string LeftRotateString_1(string str, int n) {
        if (n == 0) return str;
        if (str.size() <= 1) return str;

        int moveBit = n % str.size();

        return string(std::next(str.begin(), moveBit), str.end()) + 
            string(str.begin(), std::next(str.begin(), moveBit));
    }
};

int main() 
{
    Solution s;

    std::cout << "method 1: \n";

    std::cout << std::endl;
    return 0;
}


#include <iostream>
#include <algorithm>


using namespace std;

/*
* Name: 二进制中1的个数
* Description: 输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
*
*/
class Solution {
public:
    int  NumberOf1(int n) {
        
        int count = 0;
        unsigned int flag = 1;
        while (flag)
        {
            if (n & flag)   
                ++count;
            flag = flag << 1;
        }
        return count;
    }
    // 超时 负数时死循环
    // int  NumberOf1(int n) { 
    //     int ret = 0;
    //     while (n)
    //     {
    //         ret += n & 0x01;
    //         n = n >> 1;
    //     }
    //     return ret;
    // }
};

int main() 
{
    Solution s;

    std::cout << "method 1: \n";
    std::cout << "NumberOf1(7): 3 " << s.NumberOf1(7) << "\n";
    std::cout << "NumberOf1(19): 3 " << s.NumberOf1(19) << "\n";
    std::cout << "NumberOf1(43): 4 " << s.NumberOf1(43) << "\n";
    std::cout << "NumberOf1(128): 1 " << s.NumberOf1(128) << "\n";
    std::cout << "NumberOf1(4184): 4 " << s.NumberOf1(4184) << "\n";
    std::cout << "NumberOf1(65535): 16 " << s.NumberOf1(65535) << "\n";

    std::cout << std::endl;
    return 0;
}
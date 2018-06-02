
#include <iostream>
#include <algorithm>


using namespace std;

/*
* Name: 斐波那契数列
* Description: 大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。
* n<=39
*
*/
class Solution {
public:
    int Fibonacci(int n) {
        std::vector<int> oldValue(n+1);

        oldValue[0] = 0;
        oldValue[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
            oldValue[i] = oldValue[i-1] + oldValue[i-2];
        }

        return oldValue[n];
    }

//     int Fibonacci(int n) {
//         int f = 0, g = 1;
//         while(n--) {
//             g += f;
//             f = g - f;
//         }
//         return f;
//     }
};

int main() 
{
    Solution s;

    std::cout << "method 1: \n";
    cout << s.Fibonacci(6);
    std::cout << std::endl;
    return 0;
}
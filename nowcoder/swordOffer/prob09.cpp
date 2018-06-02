
#include <iostream>
#include <algorithm>


using namespace std;

/*
* Name: 变态跳台阶
* Description: 一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
* 求该青蛙跳上一个n级的台阶总共有多少种跳法。
*
*/
class Solution {
public:
    // 0 --> 1
    // 1 --> 1
    // 2 --> 2
    // 3 --> 4
    // 4 --> 8
    // 5 --> 16
    // n --> 2 * f(n-1)
    int jumpFloorII(int number) {
        vector<int> vec(number+1);
        vec[0] = 1;
        vec[1] = 1;
        vec[2] = 2;
        for (int i = 3; i <= number; ++i)
        {
            vec[i] = 2 * vec[i-1];
        }
        
        return vec[number];
    }
    int jumpFloorII2(int number) {
        vector<int> vec(number+1);
        vec[0] = 0;
        vec[1] = 1;
        vec[2] = 2;
        for (int i = 3; i <= number; ++i)
        {
            for (int j = i - 1; j > 0; --j)
            {
                vec[i] += vec[j];
            }
            vec[i] += 1;
        }
        
        return vec[number];
    }
};
int main() 
{
    Solution s;

    std::cout << "method 1: \n";
    cout << "jumpFloorII(3): 4 " << s.jumpFloorII(3);
    std::cout << std::endl;
    return 0;
}

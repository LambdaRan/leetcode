
#include <iostream>
#include <algorithm>


using namespace std;

/*
* Name: 跳台阶
* Description: 一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
*
*/
class Solution {
public:
    int jumpFloor(int number) {

        vector<int> vec(number+1);
        vec[0] = 0;
        vec[1] = 1;
        vec[2] = 2;
        for (int i = 3; i <= number; ++i)
        {
            vec[i] = vec[i-1] + vec[i-2];
        }
        
        return vec[number];
    }

    int jumpFloor2(int number) {
        if (number == 1) return 1;
        if (number == 2) return 2;
        return jumpFloor(number-1) + jumpFloor(number-2);
    }
};

int main() 
{
    Solution s;

    std::cout << "method 1: \n";
    cout << "jumpFloor(4): 5" << s.jumpFloor(4);
    std::cout << std::endl;
    return 0;
}
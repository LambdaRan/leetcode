
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
* /*
* * Name: 70. Climbing Stairs
* * Description: 
* You are climbing a stair case. It takes n steps to reach to the top.
* Each time you can either climb 1 or 2 steps. In how many distinct ways 
* can you climb to the top?
* 
* Note: Given n will be a positive integer.
* 
* Example 1:
* Input: 2
* Output: 2
* Explanation: There are two ways to climb to the top.
* 1. 1 step + 1 step
* 2. 2 steps
* 
* Example 2:
* Input: 3
* Output: 3
* Explanation: There are three ways to climb to the top.
* 1. 1 step + 1 step + 1 step
* 2. 1 step + 2 steps
* 3. 2 steps + 1 step
* 
* */
class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    int climbStairs(int n) 
    {    
        if (n <= 3)
            return n;
        else 
        {
            vector<int> oldValue(n+1);
            oldValue[0] = 1;
            oldValue[1] = 1;
            for (int i = 2; i <= n; ++i)
            {
                oldValue[i] = oldValue[i-1] + oldValue[i-2];
            }
            return oldValue[n];
        }
    }

    // Fibonacci Number
    // Fib(n)=Fib(n−1)+Fib(n−2)
    int climbStairs_v2(int n)
    {
        if (n == 1) {
            return 1;
        }
        int first = 1;
        int second = 2;
        for (int i = 3; i <= n; i++) {
            int third = first + second;
            first = second;
            second = third;
        }
        return second;
    }
};
std::string boolToString(bool input) {
    return input ? "True" : "False";
}
int main() 
{
    Solution s;

    std::cout << "method 1: \n";
    std::cout <<  "function(): true <------> " << boolToString(s.function()) << "\n";

    std::cout << std::endl;
    return 0;
}
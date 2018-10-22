
#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <utility>
#include <iterator>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
/*
* Name: 268. Missing Number
* Website: https://leetcode.com/problems/missing-number/description/
* Description: 
*
*/
class Solution
{
  public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    int missingNumber(vector<int>& nums) {
        int mis = 0, i = 0;
        for (int v : nums)
            mis ^= ++i ^ v; // 两个相同的数异或为零
        return mis;
    }
    // 方法一： 等差数列求和公式 Sn = n*(a1 + an)/2
    int missingNumber_v1(vector<int>& nums) {
        size_t sum = (nums.size()+1) * nums.size() / 2;
        for (int v : nums)
            sum -= v;
        return sum;        
    }
};

int main()
{
    Solution s;

    std::cout << "method 1: \n";
    //std::cout <<  "function(): true <------> " << boolToString(s.function()) << "\n";

    std::cout << std::endl;
    return 0;
}
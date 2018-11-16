
#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <utility>
#include <iterator>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;
/*
* Name: 414. Third Maximum Number
* Website: https://leetcode.com/problems/third-maximum-number/description/
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
    int thirdMax(vector<int>& nums) {
        if (nums.size() < 3) 
            return *max_element(nums.begin(), nums.end());
        std::sort(nums.begin(), nums.end());
        auto last = std::unique(nums.begin(), nums.end());
        if (last - nums.begin() < 3)
            return *max_element(nums.begin(), last);
        else
            return *std::next(last, -3);
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
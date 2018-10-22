
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
* Name: 283. Move Zeroes
* Website: https://leetcode.com/problems/move-zeroes/description/
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
    void moveZeroes(vector<int>& nums) {
        
        if (nums.empty()) return;
        int slow = 0;
        int fast = 0;
        while (fast < nums.size())
        {
            if (nums[fast] != 0)
                nums[slow++] = nums[fast++];
            else 
                ++fast;
        }
        
        while (slow < nums.size())
            nums[slow++] = 0;
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
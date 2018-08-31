
// https://leetcode.com/problems/remove-element/description/

#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <utility>
#include <iterator>
#include <string>
#include <vector>

using namespace std;
/*
* Name: 27. Remove Element
* Description: 
*
*/
class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    int removeElement(vector<int>& nums, int val) 
    {
        // nums.erase(std::remove(nums.begin(), nums.end(), val), nums.end());
        // return nums.size();
        int k = 0;
        for (size_t i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != val)
                nums[k++] = nums[i];
        }
        return k;
    }
};
std::string boolToString(bool input) {
    return input ? "True" : "False";
}
int main() 
{
    Solution s;

    std::cout << "method 1: \n";
    //std::cout <<  "function(): true <------> " << boolToString(s.function()) << "\n";

    std::cout << std::endl;
    return 0;
}
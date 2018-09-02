
// https://leetcode.com/problems/search-insert-position/description/
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
* Name: 35. Search Insert Position
* Description: 
*
*/
class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    int searchInsert(vector<int>& nums, int target) 
    {
        //return distance(nums.begin(), lower_bound(nums.begin(), nums.end(), target));
        if (nums.empty()) return 0;
        return binary_search(nums, target);
    }
    int binary_search(vector<int>& nums, int target)
    {
        int low = 0;
        int high = static_cast<int>(nums.size())-1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                low = ++mid;
            else  
                high = --mid;
        }
        return low;
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

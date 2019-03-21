
#include <iostream>
#include <algorithm>
#include <sstream>
#include <functional>
#include <utility>
#include <iterator>
#include <string>
#include <vector>

using namespace std;
/*
* Name: 448. Find All Numbers Disappeared in an Array
* WebSite: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/
* Description: 
*
*/
class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ret = {};
        int index = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            index = std::abs(nums[i]) - 1;
            nums[index] = nums[index] > 0 ? -nums[index] : nums[index];
        }
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) ret.emplace_back(i+1);
        }
        return ret;
    }
};

int main() 
{
    string line;
    while (getline(cin, line)) 
    {
        // vector<int> prices = stringToIntegerVector(line);
        
        // int ret = Solution().maxProfit_v2(prices);

        // string out = to_string(ret);
        // cout << out << endl;
    }
    return 0;
}

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
* Name: 217. Contains Duplicate
* Website: https://leetcode.com/problems/contains-duplicate/description/
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
    bool containsDuplicate(vector<int>& nums) {
        if (nums.empty()) return false;
        unordered_set<int> old;
        for (int v : nums)
        {
            if (old.find(v) == old.end())
                old.insert(v);
            else  
                return true;
        }
        return false;
    }
    bool containsDuplicate_v1(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return adjacent_find(nums.begin(), nums.end()) != nums.end();
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
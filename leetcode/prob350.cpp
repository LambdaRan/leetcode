
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
* Name: 350. Intersection of Two Arrays II
* Website: https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
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
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        if (nums1.empty() || nums2.empty()) return result;
        unordered_map<int, int> numsOneMap;
        for (auto v : nums1)
            ++numsOneMap[v];
        for (auto v : nums2)
        {
            if (numsOneMap.find(v) != numsOneMap.end() && --numsOneMap[v] >= 0)
                result.emplace_back(v);
        }
        return result;
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
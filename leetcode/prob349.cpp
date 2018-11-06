
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
* Name: 349. Intersection of Two Arrays
* Website: https://leetcode.com/problems/intersection-of-two-arrays/description/
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
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        if (nums1.empty() || nums2.empty()) return result;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        set_intersection(nums1.begin(), nums1.end(),
                        nums2.begin(), nums2.end(),
                        back_inserter(result));
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
    }
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s(nums1.begin(), nums1.end());
        vector<int> out;
        for (int x : nums2)
            if (s.erase(x))
                out.push_back(x);
        return out;
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
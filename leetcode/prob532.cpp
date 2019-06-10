
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <utility>
#include <iterator>
#include <unordered_map>
#include <cmath>
#include <cctype>
#include <limits>

#include "gtest/gtest.h"

using namespace std;

/*
* Name: 532. K-diff Pairs in an Array
* WebSite: https://leetcode.com/problems/k-diff-pairs-in-an-array/
* Description: 
*
*/
class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    int findPairs(vector<int>& nums, int k) {
        if (k < 0 || nums.size() < 2) return 0;
        std::unordered_map<int, int> numMap;
        for (int v : nums)
            ++numMap[v];
        int count = 0;
        for (const pair<int, int> & v : numMap) {
            --numMap[v.first];
            if (numMap.count(v.first+k) && numMap[v.first+k] != 0) {
                ++count;
            }
            ++numMap[v.first];
        }
        return count;
    }
    int findPairs_v2(vector<int>& nums, int k) {
        if (k < 0 || nums.size() < 2)
            return 0;
        std::sort(nums.begin(), nums.end());
        int count = 0;
        int diff = 0;
        for (size_t i = 0, j = 1; j != nums.size(); /*NOP*/) {
            diff = nums[j] - nums[i];
            if (diff < k || j <= i)
                ++j;
            else if (diff > k || (i > 0 && nums[i] == nums[i-1])) {
                ++i;
            }
            else {
                ++count;
                ++i;
            }
        }
        return count;
    }
    int findPairs_v1(vector<int>& nums, int k) {
        if (k < 0 || nums.size() < 2)
            return 0;
        std::sort(nums.begin(), nums.end());
        int count = 0;
        if (k != 0) {
            auto last = std::unique(nums.begin(), nums.end());
            nums.erase(last, nums.end());
            size_t slow = 0, fast = 1;
            while (slow < nums.size() && fast < nums.size()) {
                if (slow == fast) {
                    ++fast;
                    continue;
                }
                while (fast < nums.size() && nums[fast] - nums[slow] < k)
                    ++fast;
                if (fast == nums.size())
                    break;
                if (nums[fast] - nums[slow] == k) {
                    ++count;
                }
                ++slow;
            }
        } 
        else {
            size_t i = 0, j = 1;
            while (i < nums.size()) {
                while (j < nums.size() && nums[i] == nums[j])
                    ++j;
                if (j - i > 1)
                    ++count;
                i = j;
            }
        }
        return count;
    }
};

Solution solu; 

TEST(FindPairsTest, Positive) 
{
    std::vector<int> v1 = {3, 1, 4, 1, 5};
    EXPECT_EQ(solu.findPairs(v1, 2), 2);

    std::vector<int> v2 = {1, 2, 3, 4, 5};
    EXPECT_EQ(solu.findPairs(v2, 1), 4);

    std::vector<int> v3 = {1, 3, 1, 5, 4};
    EXPECT_EQ(solu.findPairs(v3, 0), 1);

    std::vector<int> v4 = {1, 1, 1, 1, 1,2,2,3,4,4,4,5};
    EXPECT_EQ(solu.findPairs(v4, 0),3);
}

              
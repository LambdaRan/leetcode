#include <iostream>
#include <string>
#include <algorithm>

#include "gtest/gtest.h"

using namespace std;

// Name: 594. Longest Harmonious Subsequence
// Website: https://leetcode.com/problems/longest-harmonious-subsequence/
// Description:

class Solution {
public:
    int findLHS(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        std::sort(nums.begin(), nums.end());
        int prev_count = 1;
        int result = 0;
        for (size_t idx = 0; idx < nums.size(); ++idx) {
            int count = 1;
            if (idx > 0 && nums[idx] - nums[idx - 1] == 1) {
                while (idx < nums.size() -1 && nums[idx] == nums[idx + 1]) {
                    ++count;
                    ++idx;
                }
                result = std::max(result, count + prev_count);
                prev_count = count;
            } else {
                while (idx < nums.size() -1 && nums[idx] == nums[idx + 1]) {
                    ++count;
                    ++idx;
                }
                prev_count = count;
            }
        }
        return result;
    }
    int findLHS_v2(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        int result = 0;
        std::unordered_map<int, int> nums_count;
        for (int val : nums) {
            ++nums_count[val];
        }
        for (int val : nums) {
            auto iter = nums_count.find(val+1);
            if (iter == nums_count.end()) {
                result = std::max(result, nums_count[val] + iter->second);
            }
        }
        return result;
    }
};

Solution solu;

// TEST(Fuction, one) {}
#include <iostream>
#include <string>

#include "gtest/gtest.h"

using namespace std;

// Name: 41. First Missing Positive
// Website: https://leetcode.com/problems/first-missing-positive/
// Description:

class Solution {

  public:
    int firstMissingPositive(vector<int>& nums) {
        std::set<int> s;
        for (const auto v : nums) {
            if (v > 0) {
                s.insert(v);
            }
        }
        if (s.empty()) {
            return 1;
        }
        if (*s.begin() > 1) {
            return 1;
        }
        int count = 1;
        for (auto iter = s.begin(); iter != s.end(); ++iter) {
            if (*iter != count) {
                return count;
            }
            ++count;
        }
        return count;
    }

    int firstMissingPositive_v2(vector<int>& nums) {
        for (size_t i = 0; i < nums.size(); ++i) {
            while(nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i]) {
                std::swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return nums.size() + 1;
    }

    int firstMissingPositive_v3(vector<int>& nums) {
        nums.push_back(0);
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] < 0 || nums[i] >= nums.size()) {
                nums[i] = 0;
            }
        }

        for (size_t i = 0; i < nums.size(); ++i) {
            nums[nums[i] % nums.size()] += nums.size();
        }
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] / nums.size() == 0) {
                return i;
            }
        }
        return nums.size();
    }

};

Solution solu;

// TEST(Fuction, one) {}
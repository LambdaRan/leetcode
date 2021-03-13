#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "gtest/gtest.h"

using namespace std;

// Name: 34. Find First and Last Position of Element in Sorted Array
// Website: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// Description:

class Solution {

  public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int li = 0;
        int hi = n - 1;
        while (li <= hi) {
            int m = (li + hi) / 2;
            if (nums[m] == target) {
                std::vector<int> r = {m, m};
                while (r[0] > 0 && nums[r[0]-1] == target) {
                    r[0] -= 1;
                }
                while (r[1] < n-1 && nums[r[1]+1] == target) {
                    r[1] += 1;
                }
                return r;
            } else if (nums[m] < target) {
                li = m + 1;
            } else {
                hi = m - 1;
            }
        }
        return std::vector<int>({-1, -1});
    }

    vector<int> searchRange_v2(vector<int>& nums, int target) {
        std::vector<int> res = {-1, -1};
        auto li = std::lower_bound(nums.begin(), nums.end(), target);
        if (li == nums.end() || *li != target) return res;
        auto hi = std::upper_bound(nums.begin(), nums.end(), target);
        res[0] = std::distance(nums.begin(), li);
        res[1] = std::distance(nums.begin(), hi) - 1;
        return res;
    }
};

Solution solu;

// TEST(Fuction, one) {}
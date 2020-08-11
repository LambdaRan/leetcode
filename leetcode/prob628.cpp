#include <iostream>
#include <string>

#include "gtest/gtest.h"

using namespace std;

// Name: 628. Maximum Product of Three Numbers
// Website: https://leetcode.com/problems/maximum-product-of-three-numbers/
// Description:

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // 找到最大的三个值 和 最小的两个值
    }
    int maximumProduct_v1(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int p1 = nums[0] * nums[1] * nums.back();
        int p2 = std::accumulate(nums.rbegin(), std::next(nums.rbegin(), 3), 1, std::multiplies<int>());
        return std::max(p1, p2);
    }

};

Solution solu;

// TEST(Fuction, one) {}
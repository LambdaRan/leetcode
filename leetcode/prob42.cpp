#include <iostream>
#include <string>

#include "gtest/gtest.h"

using namespace std;

// Name: 42. Trapping Rain Water
// Website: https://leetcode.com/problems/trapping-rain-water/
// Description:

class Solution {

  public:
    int trap(vector<int>& height) {
        if (height.size() < 3) {
            return 0;
        }

        int size = height.size();
        std::vector<int> left_max(size);
        std::vector<int> right_max(size);
        left_max[0] = height[0];
        for (int i = 1; i < size; ++i) {
            left_max[i] = std::max(left_max[i-1], height[i]);
        }
        right_max[size - 1] = height[size - 1];
        for (int i = size - 2; i >= 0; --i) {
            right_max[i] = std::max(right_max[i + 1], height[i]);
        }

        int max_trap_water = 0;
        for (int i = 1; i < size - 1; ++i) {
            max_trap_water += std::min(left_max[i], right_max[i]) - height[i];
        }
        return max_trap_water;
    }

    int trap_v2(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int ans = 0;
        int left_max = 0;
        int right_max = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
                ++left;
            } else {
                height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
                --right;
            }
        }
        return ans;
    }

};

Solution solu;

// TEST(Fuction, one) {}
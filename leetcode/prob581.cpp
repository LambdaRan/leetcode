#include <iostream>
#include <string>
#include <vector>
#include <limits>

#include "gtest/gtest.h"

using namespace std;

// Name: 581. Shortest Unsorted Continuous Subarray
// Website: https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
// Description:

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        int lidx = nums.size() - 1;
        int hidx = 0;
        std::vector<int> cidx(nums.size());
        for (int idx = 0; idx < nums.size(); ++idx) {
            while (!cidx.empty() && nums[cidx.back()] > nums[idx]) {
                lidx = std::min(lidx, cidx.back());
                cidx.pop_back();
            }
            cidx.push_back(idx);
        }
        cidx.clear();
        for (int idx = nums.size() - 1; idx >= 0; --idx) {
            while (!cidx.empty() && nums[cidx.back()] < nums[idx]) {
                hidx = std::max(hidx, cidx.back());
                cidx.pop_back();
            }
            cidx.push_back(idx);
        }
        return hidx - lidx > 0 ? hidx - lidx + 1: 0;
    }

    int findUnsortedSubarray_v2(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        int min = std::numeric_limits<int>::max();
        int max = std::numeric_limits<int>::min();
        bool flag = false;

        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i - 1]) {
                flag = true;
            }
            if (flag) {
                min = std::min(min, nums[i]);
            }
        }
        flag = false;
        for (size_t i = nums.size() - 2; i >= 0; --i) {
            if (nums[i] > nums[i + 1]) {
                flag = true;
            }
            if (flag) {
                max = std::max(max, nums[i]);
            }
        }

        int l, r;
        for (l = 0; l < nums.size(); ++l) {
            if (min < nums[l])
                break;
        }
        for (r = nums.size() - 1; r >= 0; r--) {
            if (max > nums[r])
                break;
        }
        return r - l < 0 ? 0 : r - l + 1;
    }

    int findUnsortedSubarray_v3(vector<int>& nums) {

        int start = -1;
        int end = -1;
        int mai = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            if (mai > nums[i]) {
                end = i;
            }

            mai = std::max(mai, nums[i]);
        }
        mai = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; --i) {
            if (mai < nums[i]) {
                start = i;
            }
            mai = std::min(mai, nums[i]);
        }

        if(start==-1 || end==-1)
            return 0;
        return end-start+1;
    }

};

Solution solu;

// TEST(Fuction, one) {}
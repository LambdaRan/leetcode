#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "gtest/gtest.h"

using namespace std;

// Name: 561. Array Partition I
// Website: https://leetcode.com/problems/array-partition-i/
// Description:

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        std::sort(nums.begin(), nums.end());
        int sum = 0;
        for (size_t idx = 0; idx < nums.size(); idx += 2) {
            sum += nums[idx];
        }
        return sum;
    }
    int arrayPairSum2(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        std::array<int, 20001> hashmap = {0};
        for (int v : nums) {
            ++hashmap[v + 10000];
        }
        int sum = 0;
        bool flag = true;
        for (size_t idx = 0; idx < hashmap.size(); ++idx) {
            if (hashmap[idx] > 0) {
                while(hashmap[idx]--) {
                    if (flag) {
                        sum += idx - 10000;
                        flag = false;
                    } else {
                        flag = true;
                    }
                }
            }
        }
        return sum;
    }

};

Solution solu;

// TEST(Fuction, one) {}
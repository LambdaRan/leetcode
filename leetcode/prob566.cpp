#include <iostream>
#include <string>

#include "gtest/gtest.h"

using namespace std;

// Name: 566. Reshape the Matrix
// Website: https://leetcode.com/problems/reshape-the-matrix/
// Description:

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if (nums.empty() || r * c != nums.size() * nums[0].size()) {
            return nums;
        }
        std::vector<std::vector<int>> results(r, std::vector<int>(c, 0));
        size_t nidx = 0;
        size_t nidy = 0;
        for (size_t idx = 0; idx < nums.size(); ++idx) {
            for (size_t idy = 0; idy < nums[idx].size(); ++idy) {
                results[nidx][nidy] = nums[idx][idy];
                if (++nidy == c) {
                    nidy = 0;
                    ++nidx;
                }
            }
        }
        return results;
    }

    vector<vector<int>> matrixReshape_v2(vector<vector<int>>& nums, int r, int c) {
        if (nums.empty() || r * c != nums.size() * nums[0].size()) {
            return nums;
        }
        std::vector<std::vector<int>> results(r, std::vector<int>(c, 0));
        size_t count = 0;
        for (size_t idx = 0; idx < nums.size(); ++idx) {
            for (size_t idy = 0; idy < nums[idx].size(); ++idy) {
                results[count/r][count%c] = nums[idx][idy];
            }
        }
        return results;
    }

};

Solution solu;

// TEST(Fuction, one) {}
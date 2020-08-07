#include <iostream>
#include <string>

#include "gtest/gtest.h"

using namespace std;

// Name: 598. Range Addition II
// Website: https://leetcode.com/problems/range-addition-ii/
// Description:

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        for (const auto& pair : ops) {
            m = std::min(m, pair[0]);
            n = std::min(n, pair[1]);
        }
        return m * n;
    }

};

Solution solu;

// TEST(Fuction, one) {}
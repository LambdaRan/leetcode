#include <iostream>
#include <string>

#include "gtest/gtest.h"

using namespace std;

// Name: 605. Can Place Flowers
// Website: https://leetcode.com/problems/can-place-flowers/
// Description:

class Solution {
public:

    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n * 2 - 1 > static_cast<int>(flowerbed.size())) return false;
        int count = 0;
        for (size_t idx = 0; idx < flowerbed.size(); ++idx) {
            if (flowerbed[idx] == 0 &&
                (idx == 0 || flowerbed[idx - 1] == 0) &&
                (idx == flowerbed.size() - 1 || flowerbed[idx + 1] == 0)) {
                flowerbed[idx] = 1;
                if (++count == n) return true;
            }
        }
        return false;
    }


};

Solution solu;

// TEST(Fuction, one) {}
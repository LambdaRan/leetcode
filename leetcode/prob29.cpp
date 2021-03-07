#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>

#include "gtest/gtest.h"

using namespace std;

// Name: 29. Divide Two Integers
// Website: https://leetcode.com/problems/divide-two-integers/
// Description:

class Solution {

  public:
    int divide(int dividend, int divisor) {
        if (dividend == std::numeric_limits<int>::min() && divisor == -1) {
            return std::numeric_limits<int>::max();
        }
        long dvd = std::labs(dividend);
        long dvs = std::labs(divisor);
        long ans = 0;
        int sign = ((dividend > 0) ^ (divisor > 0)) ? -1 : 1;
        while (dvd >= dvs) {
            long temp = dvs;
            long m = 1;
            while (temp << 1 <= dvd) {
                temp <<= 1;
                m <<= 1;
            }
            dvd -= temp;
            ans += m;
        }
        return sign * ans;
    }


};

Solution solu;

// TEST(Fuction, one) {}
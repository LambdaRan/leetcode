
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <utility>
#include <iterator>
#include <unordered_map>
#include <cmath>
#include <cctype>

#include "gtest/gtest.h"

using namespace std;
/*
* Name: 504. Base 7
* WebSite: https://leetcode.com/problems/base-7/
* Description: 
*
*/
class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    string convertToBase7(int num) {

        if (num == 0) return string("0");
        string result = "";
        bool isNegative = num < 0;
        num = isNegative ? -num : num;
        const string toChar = "0123456789-";
        const int base = 7;
        int remainder = 0;
        while (num) {
            remainder = num % base;
            num /= base;
            result.push_back(toChar[remainder]);
        }
        if (isNegative)
            result.push_back(toChar.back());
        std::reverse(result.begin(), result.end());
        return result;
    }
};


Solution s; 

TEST(ConvertToBase7Test, Negative) 
{
    EXPECT_EQ("-10", s.convertToBase7(-7));
    EXPECT_EQ("-202", s.convertToBase7(-100));
}

TEST(ConvertToBase7Test, Zero)
{
    EXPECT_EQ("0", s.convertToBase7(0));
}

TEST(ConvertToBase7Test, Positive)
{
    EXPECT_EQ("202", s.convertToBase7(100));
}
              
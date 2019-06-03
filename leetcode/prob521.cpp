
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <utility>
#include <iterator>
#include <unordered_set>
#include <cmath>
#include <cctype>

#include "gtest/gtest.h"

using namespace std;
/*
* Name: 521. Longest Uncommon Subsequence I
* WebSite: https://leetcode.com/problems/longest-uncommon-subsequence-i/
* Description: 
*
*/
class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
     int findLUSlength(string a, string b) {
         if (a == b) return -1;
         return std::max(a.size(), b.size());
    }
};


Solution solu; 

TEST(DetectCapitalUseTest, Positive) 
{
    EXPECT_TRUE(solu.detectCapitalUse("Hello"));
    EXPECT_TRUE(solu.detectCapitalUse("world"));
    EXPECT_TRUE(solu.detectCapitalUse("LAMBDA"));

    EXPECT_FALSE(solu.detectCapitalUse("LeetCode"));
    EXPECT_FALSE(solu.detectCapitalUse("rAn"));
}

              
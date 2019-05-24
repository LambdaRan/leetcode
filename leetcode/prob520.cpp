
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
* Name: 520. Detect Capital
* WebSite: https://leetcode.com/problems/detect-capital/
* Description: 
*
*/
class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    bool detectCapitalUse_v1(string word) {
        //if (word.empty()) return false;
        size_t cntUpper = 0;
        size_t cntLower = 0;
        for (size_t i = 1; i < word.size(); ++i) {
            if (std::isupper(word[i]))
                ++cntUpper;
            else 
                ++cntLower;
        }
        if (std::islower(word[0])) {
            return (word.size()-1) == cntLower;
        } 
        else {
            //std::cout << "cntUpper:" << cntUpper << " cntLower:" << cntLower << std::endl;
            return std::max(cntUpper,cntLower) == (word.size()-1);
        }
    }
    bool detectCapitalUse(string word) {
        size_t cntUpper = 0;

        for (auto ch : word) {
            if (std::isupper(ch))
                ++cntUpper;
        }
        return (cntUpper==word.size()) || (cntUpper==0) || (cntUpper==1 && std::isupper(word[0]));
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

              
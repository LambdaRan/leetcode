

// https://leetcode.com/problems/longest-valid-parentheses/description/

#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
/*
* Name: 32. Longest Valid Parentheses
* Description: 
* Given a string containing just the characters '(' and ')', find the length of the longest 
* valid (well-formed) parentheses substring.
* 
* Example 1:
* Input: "(()"
* Output: 2
* Explanation: The longest valid parentheses substring is "()"
* 
* Example 2:
* Input: ")()())"
* Output: 4
* Explanation: The longest valid parentheses substring is "()()"
* 
*/
class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    int longestValidParentheses1(string s) 
    {
        int maxans = 0;
        std::vector<int> dp(s.length());
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == '}') {
                if (s[i-1] == '{') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '{') {
                    dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
                maxans = std::max(maxans, dp[i]);
            }
        }
        return maxans;
    }
};

// "()(())"
// 6

// ()(()
// 2
int main() 
{
    Solution s;

    std::cout << "method 1: \n";
//    std::cout <<  "function(): true <------> " << boolToString(s.function()) << "\n";
    string in = "";
    while (std::cin >> in) {
        std::cout << s.longestValidParentheses(in) << std::endl;
    }
    std::cout << std::endl;
    return 0;
}
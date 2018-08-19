

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
    int longestValidParentheses(string s) 
    {
        if (s.size() <= 1) return 0;
        vector<char> stack;
        int result = 0;
        int longestValid = 0;
        for (char ch : s)
        {
            if (ch == '(')
            {
                if (!stack.empty() && stack.back() == '(')
                {
                    result = 0;
                    continue;
                }
                stack.push_back(ch);
            }
            else  
            {
                if (stack.empty())
                    continue;
                else  
                {
                    if (stack.back() == '(')
                    {
                        result += 2;
                        longestValid = max(longestValid, result);
                    }
                    else  
                    {
                        result = 0;
                    }    
                    stack.pop_back();
                }
            }
        }
        return longestValid;
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
    std::cout <<  "function(): true <------> " << boolToString(s.function()) << "\n";

    std::cout << std::endl;
    return 0;
}

// https://leetcode.com/problems/valid-parentheses/description/
#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <utility>
#include <iterator>
#include <string>
#include <vector>

using namespace std;
/*
* Name: 20. Valid Parentheses
* Description: 
* Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
* determine if the input string is valid.
* 
* An input string is valid if:
* Open brackets must be closed by the same type of brackets.
* Open brackets must be closed in the correct order.
* 
* Note that an empty string is also considered valid.
* 
* Example 1:
* Input: "()"
* Output: true
* 
* Example 2:
* Input: "()[]{}"
* Output: true
* 
* Example 3:
* Input: "(]"
* Output: false
* 
* Example 4:
* Input: "([)]"
* Output: false
* 
* Example 5:
* Input: "{[]}"
* Output: true
*/
class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    bool isValid(string s) 
    {
        if (s.empty()) return true;
        vector<char> brackets; 
        for (char ch : s)  
        {
            switch(ch)
            {
                case '(':
                case '{':
                case '[':
                    brackets.push_back(ch);
                    break;
                case ')':
                    if (brackets.empty() || brackets.back() != '(')
                        return false;
                    brackets.pop_back();
                    break;
                case '}':
                    if (brackets.empty() || brackets.back() != '{')
                        return false;
                    brackets.pop_back();
                    break;
                case ']':
                    if (brackets.empty() || brackets.back() != '[')
                        return false;
                    brackets.pop_back();
                    break;
                default: return false;
            }
        }
        // if (brackets.empty())
        //     return true;
        // return false;
        reutrn brackets.empty();
    }
};
std::string boolToString(bool input) {
    return input ? "True" : "False";
}
int main() 
{
    Solution s;
    string line;
    while (getline(cin, line))
    {
        std::cout << boolToString(s.isValid(line)) << "\n";
    }

    std::cout << std::endl;
    return 0;
}
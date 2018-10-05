
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
* Name: 125. Valid Palindrome
* Website: https://leetcode.com/problems/valid-palindrome/description/
* Description: 
*
*/
class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    bool isPalindrome(string s) {
        if (s.empty()) return true;
        int leftIndex = 0;
        int rightIndex = static_cast<int>(s.size())-1;
        while (leftIndex < rightIndex)
        {
            while(leftIndex < rightIndex && !isalnum(s[leftIndex]))
                ++leftIndex;
            while(leftIndex < rightIndex && !isalnum(s[rightIndex]))
                --rightIndex;
            if (!(leftIndex < rightIndex)) break;
            if (tolower(s[leftIndex]) != tolower(s[rightIndex]))
                return false;
            ++leftIndex;
            --rightIndex;
        }
        return true;
    }
};
std::string boolToString(bool input) {
    return input ? "True" : "False";
}
int main() 
{
    Solution s;

    std::cout << "method 1: \n";
    //std::cout <<  "function(): true <------> " << boolToString(s.function()) << "\n";

    std::cout << std::endl;
    return 0;
}
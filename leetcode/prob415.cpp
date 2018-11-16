
#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <utility>
#include <iterator>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;
/*
* Name: 415. Add Strings
* Website: https://leetcode.com/problems/add-strings/description/
* Description: 
*
*/
class Solution
{
  public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    string addStrings(string num1, string num2) {
        if (num1.empty()) return num2;
        if (num2.empty()) return num1;
        const string digits = "0123456789";
        int oneIdex = static_cast<int>(num1.size())-1;
        int twoIdex = static_cast<int>(num2.size())-1;
        int carry = 0;
        string result = "";
        while (oneIdex >= 0 || twoIdex >= 0 || carry)
        {
            if (oneIdex >= 0)
                carry += num1[oneIdex--]-'0';
            if (twoIdex >= 0)
                carry += num2[twoIdex--]-'0';
            if (carry < 10)
            {
                result += digits[carry];
                carry = 0;
            }
            else 
            {
                result += digits[carry-10];
                carry = 1;
            }
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
    string addStrings_v1(string num1, string num2) {
        if (num1.empty()) return num2;
        if (num2.empty()) return num1;
        const string digits = "0123456789";
        std::reverse(num1.begin(), num1.end());
        std::reverse(num2.begin(), num2.end());
        size_t i = 0;
        string result = "";
        int carry = 0;
        while (i < num1.size() && i < num2.size())
        {
            int sum = (num1[i]-'0') +( num2[i]-'0') + carry;
            if (sum < 10)
            {
                result += digits[sum];
                carry = 0;
            }
            else
            {
                result += digits[sum-10];
                carry = 1;
            }
            ++i;
        }
        while (i < num1.size())
        {
            int sum = num1[i++]-'0'+carry;
            if (sum < 10)
            {
                result += digits[sum];
                carry = 0;
            }
            else 
            {
                result += digits[sum-10];
                carry = 1;
            }
        }
        while (i < num2.size())
        {
            int sum = num2[i++]-'0'+carry;
            if (sum < 10)
            {
                result += digits[sum];
                carry = 0;
            }
            else 
            {
                result += digits[sum-10];
                carry = 1;
            }
        }
        if (carry == 1)
            result += '1';
        std::reverse(result.begin(), result.end());
        return result;
    }
};

int main()
{
    Solution s;

    std::cout << "method 1: \n";
    //std::cout <<  "function(): true <------> " << boolToString(s.function()) << "\n";

    std::cout << std::endl;
    return 0;
}
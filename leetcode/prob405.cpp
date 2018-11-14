
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
* Name: 405. Convert a Number to Hexadecimal
* Website: https://leetcode.com/problems/convert-a-number-to-hexadecimal/description/
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
    string toHex(int num) {
        if (num == 0) return "0";
        const string digitsHex = "0123456789abcdef";
        string result = "";
        for (int i = 0; num && i < 8; ++i)
        {
            result = digitsHex[num & 0xf] + result;
            num >>= 4;
        }
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
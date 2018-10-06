
#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <utility>
#include <iterator>
#include <string>
#include <vector>
#include <map>

using namespace std;
/*
* Name: 171. Excel Sheet Column Number
* Website: https://leetcode.com/problems/excel-sheet-column-number/description/
* Description: 
*
*/
class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    int titleToNumber(string s) {
        if (s.empty()) return 0;
        const int base = 26;
        int result = 0;
        for (int i = static_cast<int>(s.size())-1, powTwoSix = 1; 
            i >= 0; 
            --i, powTwoSix *= base)
        {
            result += (s[i]-'A'+1) * powTwoSix;
        }
        return result;
    }
    // 26进制转换成十进制
    int titleToNumber_v1(string s) {
        if (s.empty()) return 0;
        const int base = 26;
        int result = 0;
        reverse(s.begin(), s.end());
        for (int i = 0; i < static_cast<int>(s.size()); ++i)
            result += (s[i]-'A'+1) * pow(base, i);
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

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
* Name: 168. Excel Sheet Column Title
* Website: https://leetcode.com/problems/excel-sheet-column-title/description/
* Description: 
*
*/
class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    string convertToTitle(int n) {
        const string exelSheet = "0ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        const int base = 26;
        string result;
        while (n)
        {
            int residual = n % base;
            if (residual == 0)
            {
                result += exelSheet[26];
                n -= base;
            }
            else 
            {
                result += exelSheet[residual];
            }
            n /= base;
        }
        reverse(result.begin(), result.end());
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
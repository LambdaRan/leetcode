
#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <utility>
#include <iterator>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
/*
* Name: 263. Ugly Number
* Website: https://leetcode.com/problems/ugly-number/description/
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
    bool isUgly(int value) {
        if (value <= 0) return false;
        int base[] = {2,5,3};
        for (int i = 0; i < 3; ++i)
        {
            int quotient = value / base[i];
            int remain = value % base[i];
            while (remain == 0)
            {
                value = quotient;
                quotient = value /base[i];
                remain = value % base[i];
            }
        }
        return value == 1;
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
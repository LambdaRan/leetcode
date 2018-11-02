
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
* Name: 342. Power of Four
* Website: https://leetcode.com/problems/power-of-four/description/
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
    bool isPowerOfFour(int num) {
        if (num <= 0) return false;
        while (num % 4 == 0) num /= 4;
        return num == 1;
    }
    bool isPowerOfFour_v2(int num) {
        return num > 0 && (num & (num - 1)) == 0 && (num - 1) % 3 == 0;
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
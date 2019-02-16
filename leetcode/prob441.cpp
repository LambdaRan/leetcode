
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
* Name: 441. Arranging Coins
* Website: https://leetcode.com/problems/arranging-coins/description/
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
    int arrangeCoins(int n) {
        if (n == 0) return 0;

        int rows = 0;
        for (int need = 1; need <= n; ++need) {
            ++rows;
            n -= need;
        }
        return rows;
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
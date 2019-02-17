
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
    // 等差数列 sum = (x + 1) * x / 2
    //return floor(-0.5+sqrt((double)2*n+0.25));

    // 二分查找
    int arrangeCoins_binary(int n) {
        if (n < 1) return 0;

        long long start = 1LL;
        long long end = (long long)n + 1;

        while (start < end) {
            long long middle = start + (end - start) / 2;
            if (middle * (middle + 1) / 2 <= n && (middle + 1) * (middle + 2) / 2 > n)
                return middle;
            else if (middle * (middle + 1) / 2 > n) end = middle;
            else start = middle;
        }

        return start;
    }
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

#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <utility>
#include <iterator>
#include <string>
#include <vector>
#include <bitset>

using namespace std;
/*
* Name: 204. Count Primes
* Website: https://leetcode.com/problems/count-primes/description/
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
    // Eratosthenes筛选算法
    int countPrimes(int n) {
        vector<bool> isPrimer(n, true);
        for (int i = 2; i*i < n; ++i)
        {
            if (isPrimer[i])
            {
                // 将某个数的倍数都标记为非素数
                for (int j = i*i; j < n; j+=i)
                {
                    isPrimer[j] = false;
                }
            }
        }
        return count(isPrimer.begin(), isPrimer.end(), true);
        // int count = 0;
        // for (int i = 2; i < n; ++i)
        // {
        //     if (isPrimer[i])
        //         ++count;
        // }
        // return count;
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
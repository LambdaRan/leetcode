
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
    // Timer out limits
    int countPrimes(int n) {
        if (n < 2) return 0;
        int count = 0;
        int j = 0;
        for (int i = 2; i < n; ++i)
        {
            for(j = 2; j <= sqrt(i); j++)
                if(i % j == 0)  break;
            if(j > sqrt(i)) ++count;
        }
        return count;
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
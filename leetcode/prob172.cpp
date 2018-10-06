
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
* Name: 172. Factorial Trailing Zeroes
* Website: https://leetcode.com/problems/factorial-trailing-zeroes/description/
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
    // 查表
    int trailingZeroes(int n)
    {
        int count = 0;
        const int limi[] = {5, 25, 125, 625, 3125, 15625, 78125, 390625, 1953125, 9765625, 48828125, 244140625, 1220703125};
        const int elem[] = {1, 6, 31, 156, 781, 3906, 19531, 97656, 488281, 2441406, 12207031, 61035156, 305175781};
        int tmp = n;
        for (int i = 12; i >= 0; i--)
        {
            while (n >= limi[i])
            {
                count += elem[i];
                n -= limi[i];
            }
        }
        return count;
    }
    int trailingZeroes_v1(int n)
    {
        return n != 0 ? (n / 5 + trailingZeroes_v1(n / 5)) : 0;
    }
    int trailingZeroes_v2(int n) {
        int res=0;
        for(long long i=5;n/i>0;i*=5)
            res+=n/i;
        return res;
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
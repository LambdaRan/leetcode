
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
* Name: 191. Number of 1 Bits
* Website: https://leetcode.com/problems/number-of-1-bits/description/
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
    int hammingWeight(uint32_t n) {
        int bits = 0;
        int mask = 1;
        for (int i = 0; i < 32; i++) {
            if ((n & mask) != 0) {
                bits++;
            }
            mask <<= 1;
        }
        return bits;
    }
    int hammingWeight_v1(int n) {
        int sum = 0;
        while (n != 0) {
            sum++;
            n &= (n - 1);
        }
        return sum;
    }
    int hammingWeight_v2(uint32_t n) {
        return bitset<32>(n).count();
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
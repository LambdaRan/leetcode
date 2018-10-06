
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
* Name: 190. Reverse Bits
* Website: https://leetcode.com/problems/reverse-bits/description/
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
    uint32_t reverseBits(uint32_t n) {
        
    }
    uint32_t reverseBits_v1(uint32_t n) {
        std::bitset<32> num(n);
        string str = num.to_string();
        std::reverse(str.begin(), str.end());
        return std::bitset<32>(str).to_ulong();
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
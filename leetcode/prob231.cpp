
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
* Name: 231. Power of Two
* Website: https://leetcode.com/problems/power-of-two/description/
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
    // https://leetcode.com/problems/power-of-two/discuss/63966/4-different-ways-to-solve-Iterative-Recursive-Bit-operation-Math
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        // Power of 2 means only one bit of n is '1', 
        // so use the trick n&(n-1)==0 to judge whether that is the case
        return !(n&(n-1)); // return n > 0 && (n ^ (n & -n)) == 0;
    }
    bool isPowerOfTwo_my(int n) {
        if (n == 0) return false;
        // if (n == 1) return true;
        // while (n != 1)
        // {
        //     if (n%2 != 0) return false;
        //     n /= 2;
        // }
        while (n%2 == 0) n /= 2;
        return n == 1;
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
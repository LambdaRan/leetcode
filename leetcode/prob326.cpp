
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
* Name: 326. Power of Three
* Website: https://leetcode.com/problems/power-of-three/description/
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
    bool isPowerOfThree(int n) {
        if (n == 0) return false;
        while (n % 3 == 0) n /= 3;
        return n == 1;
    }
    //bool IsPowerOfThree(int n) {
    // // 1162261467 is 3^19,  3^20 is bigger than int 
    // return n > 0 && (1162261467 % n == 0);
    //}
};

int main()
{
    Solution s;

    std::cout << "method 1: \n";
    //std::cout <<  "function(): true <------> " << boolToString(s.function()) << "\n";

    std::cout << std::endl;
    return 0;
}
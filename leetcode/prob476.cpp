#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <utility>

#include <cctype>

using namespace std;
/*
* Name: 463. Island Perimeter
* WebSite: https://leetcode.com/problems/island-perimeter/
* Description: 
*
*/
class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    int findComplement(int num) {
        int res = 0;
        int idx = 0;
        for (; num > 0; num >>= 1, ++idx) {
            if ((num & 0x01) == 0) {
                res |= (0x01 << idx);
            }
        }
        return res;
    }  
};

int main() 
{
    Solution s;

    std::cout << "method 1: \n";

    std::cout << std::endl;
    return 0;
}
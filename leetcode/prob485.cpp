
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
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCon = 0;
        int curCon = 0;
        for (int v : nums) {
            if (v == 0) {
                maxCon = std::max(maxCon, curCon);
                curCon = 0;
            } else {
                curCon += v;
            }
        }
        return std::max(maxCon, curCon);
    }   
};

int main() 
{
    Solution s;

    std::cout << "method 1: \n";

    std::cout << std::endl;
    return 0;
}                
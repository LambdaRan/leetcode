
#include <iostream>
#include <algorithm>
#include <sstream>
#include <functional>
#include <utility>
#include <iterator>
#include <string>
#include <vector>

using namespace std;
/*
* Name: 453. Minimum Moves to Equal Array Elements
* WebSite: https://leetcode.com/problems/minimum-moves-to-equal-array-elements/description/
* Description: 
*
*/
class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    int minMoves(vector<int>& nums) {
        size_t n = nums.size();
        if(n <= 1)   return 0;
        int minEle = nums[0];
        long allSum = nums[0];
        for(size_t i = 1; i < n; ++i) {
            minEle = min(minELe, nums[i]);
            allSum += nums[i];
        }
        return allSum - long(minELe)*long(n); 
        // int minNum = nums[0];
        // int minIndex = 0;
        
        // for(int i = 1; i < nums.size(); i++) {
        //     if(nums[i] < minNum) {
        //         minNum = nums[i];
        //         minIndex = i;
        //     }
        // }
        
        // int moves = 0;
        
        // for(int i = 0; i < nums.size(); i++) {
        //     if(i != minIndex) {
        //         moves += nums[i] - minNum;
        //     }
        // }
        
        // return moves;
        // int allSum = std::accumulate(nums.begin(), nums.end(), 0);
        // int minELe = *std::min_element(nums.begin(), nums.end());
        // return allSum-minELe*nums.size();
    }
};

int main() 
{
    string line;
    while (getline(cin, line)) 
    {
        // vector<int> prices = stringToIntegerVector(line);
        
        // int ret = Solution().maxProfit_v2(prices);

        // string out = to_string(ret);
        // cout << out << endl;
    }
    return 0;
}
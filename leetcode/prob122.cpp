
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
* Name: 122. Best Time to Buy and Sell Stock II
* WebSite: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
* Description: 
*
*/
class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    int maxProfit_v2(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        int maxPri = 0;
        for (size_t i = 1; i < prices.size(); ++i)
        {
            if (prices[i] > prices[i-1])
                maxPri += prices[i] - prices[i-1];
        }
        return maxPri;
    }
    // 把所有的正数加起来
    int maxProfit_v1(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        int one = 0;
        int two = 0;
        for (size_t i = 1; i < prices.size(); ++i)
        {
            two = max(one, one + (prices[i]-prices[i-1]));
            one = two;
        }
        return two;
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
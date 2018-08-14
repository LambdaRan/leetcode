
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>

#include <ctype.h>

using namespace std;
/*
* Name: 121. Best Time to Buy and Sell Stock
* Description: Say you have an array for which the ith element is the price of 
* a given stock on day i.
* If you were only permitted to complete at most one transaction 
* (i.e., buy one and sell one share of the stock), design an algorithm to 
* find the maximum profit.
* 
* Note that you cannot sell a stock before you buy one.
* 
* Example 1:
* Input: [7,1,5,3,6,4]
* Output: 5
* Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
*              Not 7-1 = 6, as selling price needs to be larger than buying price.
* Example 2:
* Input: [7,6,4,3,1]
* Output: 0
* Explanation: In this case, no transaction is done, i.e. max profit = 0.
*
*/
class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    int maxProfit(vector<int>& prices) 
    {
        int pSize = static_cast<int>(prices.size());
        if (pSize <= 1) return 0;
        int maxPriceIdx = 0;
        int minPriceIdx = 0;
        int maxProfitValue = 0;
        for (int i = 1; i < pSize; ++i)
        {
            if (prices[i] > prices[maxPriceIdx])
                maxPriceIdx = i;
            if (prices[i] < prices[minPriceIdx])
            {
                minPriceIdx = i;
                maxPriceIdx = i;
            }
            if (minPriceIdx < maxPriceIdx)
                maxProfitValue = std::max(maxProfitValue, prices[maxPriceIdx]-prices[minPriceIdx]);
        }
        return maxProfitValue;
    }
    // 动态规划
    int maxProfit_v2(vector<int>& prices) 
    {
        if (prices.size() <= 1) return 0;
        vector<int> dp(prices.size());
        dp[0] = 0;
        int maxProfitValue = 0;
        for (size_t i = 1; i < prices.size(); ++i)
        {
            dp[i] = std::max(dp[i-1], dp[i-1]+(prices[i]-prices[i-1]));
            maxProfitValue = std::max(maxProfitValue, dp[i]);
        }
        return maxProfitValue;
    }


};
void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}
int main() 
{
    string line;
    while (getline(cin, line)) 
    {
        vector<int> prices = stringToIntegerVector(line);
        
        int ret = Solution().maxProfit(prices);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}

// https://leetcode.com/problems/min-cost-climbing-stairs/description/
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
/*
* Name: 746. Min Cost Climbing Stairs
* Description: 
* On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).
* Once you pay the cost, you can either climb one or two steps. 
* You need to find minimum cost to reach the top of the floor, and you can either start 
* from the step with index 0, or the step with index 1.
* 
* Example 1:
* Input: cost = [10, 15, 20]
* Output: 15
* Explanation: Cheapest is start on cost[1], pay that cost and go to the top.
* 
* Example 2:
* Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
* Output: 6
* Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].
* 
* Note:
* cost will have a length in the range [2, 1000].
* Every cost[i] will be an integer in the range [0, 999].
* */
class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    int minCostClimbingStairs(vector<int>& cost) 
    {
        size_t size = cost.size();
        if (size == 2) return min(cost[0], cost[1]);
        vector<int> dp(size);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (size_t i = 2; i < size; ++i)
        {
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }
        return min(dp[size-1], dp[size-2]);
    }

    int minCostClimbingStairs_v2(vector<int>& cost) 
    {
        int dp1 = 0;
        int dp2 = 0;
        for (size_t i = 0; i < cost.size(); ++i)
        {
            int dp0 = cost[i] + min(dp1, dp2);
            dp2 = dp1;
            dp1 = dp0;
        }
        return min(dp1, dp2);
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

// 输入形式 [1,2,3,4,5,6]
// 输出 
int main() 
{
    string line;
    while (getline(cin, line)) 
    {
        vector<int> prices = stringToIntegerVector(line);
        
        int ret = Solution().maxProfit_v2(prices);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
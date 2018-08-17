
// https://www.geeksforgeeks.org/minimum-cost-to-reach-the-top-of-the-floor-by-climbing-stairs/

#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
/*
* Name: Minimum cost to reach the top of the floor by climbing stairs
* Description: 
* Given N non-negative integers which signifies the cost of the moving from each stair. 
* Paying the cost at i-th step, you can either climb one or two steps. 
* Given that one can start from the 0-the step or 1-the step, 
* the task is to find the minimum cost to reach the top of the floor(N+1) by climbing N stairs.
* 
* Examples:
* Input: a[] = [16,19,10,12,18]
* Output: 31
* Start from 19 and then move to 12. 
* 
* Input: a[] = {2,5,3,1,7,3,4}
* Output: 9 
* 2->3->1->3
*/
class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    int miniCost(vector<int>& cost) 
    {
        size_t size = cost.size();
        if (size == 1) return cost[0];
        if (size == 2) 
            return std::min(cost[0], cost[1]);
        return std::min(_miniCost(cost, 0, 1, cost[0]),
                        _miniCost(cost, 1, 2, cost[1]));
    }
    int _miniCost(vector<int>& cost, int prev, int cur, int curCost)
    {
        if (cur == cost.size()-1)
        {
            if (cur - 1 == prev)
                return curCost;
            else  
                return curCost+cost[cur];
        }
        else  
        {
            if (cur - 1 == prev) // 前一个选了
                return std::min(_miniCost(cost, prev, cur+1, curCost),
                                _miniCost(cost, cur, cur+1, curCost+cost[cur]));
            else  
                return _miniCost(cost, cur, cur+1, curCost+cost[cur]);
        }
    }

    // dp[i] = cost[i] + min(dp[i+1], dp[i+2]).
    int miniCost_v2(vector<int>& cost)
    {
        size_t size = cost.size();
        if (size == 1) return cost[0];
        vector<int> dp(size);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (size_t i = 2; i < size; ++i)
        {
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        }
        return min(dp[size-1], dp[size-2]);
    }
    int miniCost_v3()
    {
        int dp1 = 0;
        int dp2 = 0;
        // traverse till N-th stair
        for (size_t i = 0; i < n; ++i) 
        {
            int dp0 = cost[i] + min(dp1, dp2);
            // update the last two stairs value
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
        
        int ret = Solution().miniCost(prices);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}

// https://leetcode.com/problems/house-robber/description/
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
/*
* Name: 198. House Robber
* Description: 
* You are a professional robber planning to rob houses along a street. 
* Each house has a certain amount of money stashed, the only constraint 
* stopping you from robbing each of them is that adjacent houses have 
* security system connected and it will automatically contact the police 
* if two adjacent houses were broken into on the same night.
* 
* Given a list of non-negative integers representing the amount of money of each house, 
* determine the maximum amount of money you can rob tonight without alerting the police.
* 
* Example 1:
* Input: [1,2,3,1]
* Output: 4
* Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
*              Total amount you can rob = 1 + 3 = 4.
* 
* Example 2:
* Input: [2,7,9,3,1]
* Output: 12
* Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
*              Total amount you can rob = 2 + 9 + 1 = 12.
*/
class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */

    int rob(vector<int>& nums) 
    {
        size_t size = nums.size();
        if (size == 0) return 0;
        if (size <= 2) 
            return *std::max_element(nums.begin(), nums.end());
        vector<int> dp(size);
        dp[0] = nums[0];
        dp[1] = max(nums[1], dp[0]);
        for (size_t i = 2; i < size; ++i)
        {
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }
        return dp[size-1];
    }


    //  Time Limit Exceeded 
    int rob_v1(vector<int>& nums) 
    {
        size_t size = nums.size();
        if (size == 0) return 0;
        if (size == 1) return nums[0];
        if (size == 2) return std::max(nums[0], nums[1]);
        return std::max(_maxMoney(nums, 0, 1, nums[0]),
                        _maxMoney(nums, 1, 2, nums[1])); 
    }
    int _maxMoney(vector<int>& money, int prev, int cur, int curMoney)
    {
        if (cur == money.size()-1)
        {
            if (cur - 1 == prev) // 前一家已经抢劫
                return curMoney;
            else  
                return curMoney+money[cur];
        }
        else  
        {
            if (cur - 1 == prev) // 前一家已经抢劫
                return _maxMoney(money, prev, cur+1, curMoney);
            else  
                return max(_maxMoney(money, cur, cur+1, curMoney+money[cur]),
                            _maxMoney(money, prev, cur+1, curMoney));
        }
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
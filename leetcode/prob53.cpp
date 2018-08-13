
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>

#include <ctype.h>
#include <limits.h>

using namespace std;
/*
* Name: 53. Maximum Subarray
* Description: 
* Given an integer array nums, find the contiguous subarray (containing at least one number) 
* which has the largest sum and return its sum.
* 
* Example:
* Input: [-2,1,-3,4,-1,2,1,-5,4],
* Output: 6
* Explanation: [4,-1,2,1] has the largest sum = 6.
* 
* Follow up:
* If you have figured out the O(n) solution, try coding another solution using the divide 
* and conquer approach, which is more subtle.
*
*/
class Solution {
public:
    /*
    * Runtime:   4 ms
    * Your runtime beats  100% of cpp submissions. 
    */
    int maxSubArray(vector<int>& nums) 
    {
        size_t numsSize = nums.size();
        if (numsSize == 1) return nums[0];
        int curSum = nums[0];
        int maxSum = curSum;
        if (nums[0] < 0)
            curSum = 0;
        for (size_t i = 1; i < numsSize; ++i)
        {
            curSum += nums[i];
            if (curSum > maxSum)
                maxSum = curSum;
            if (curSum < 0)
            {
                curSum = 0;
            }
        }
        return maxSum;
    }
    // 动态规划
    int maxSubArray_v2(vector<int>& nums) 
    {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        int maxSum = nums[0];
        for (size_t i = 1; i < nums.size(); ++i)
        {
            dp[i] = nums[i] + (dp[i-1] > 0 ? dp[i-1] : 0);
            maxSum = std::max(maxSum, dp[i]);
        }
        return maxSum;
    }

    // https://www.geeksforgeeks.org/divide-and-conquer-maximum-sum-subarray/
    // 分而治之
    int maxSubArray_v3(vector<int>& nums)
    {
        return maxSubArraySum(nums, 0, static_cast<int>(nums.size())-1);
    }
    // 求以arr[m]为中间值左右两边最大和
    int maxCrossingSum(vector<int>& arr, int l, int m, int h)
    {
        // Include elements on left of mid.
        int sum = 0;
        int left_sum = INT_MIN;
        for (int i = m; i >= l; --i)
        {
            sum = sum + arr[i];
            if (sum > left_sum)
            left_sum = sum;
        }
    
        // Include elements on right of mid
        sum = 0;
        int right_sum = INT_MIN;
        for (int i = m+1; i <= h; i++)
        {
            sum = sum + arr[i];
            if (sum > right_sum)
            right_sum = sum;
        }
    
        // Return sum of elements on left and right of mid
        return left_sum + right_sum;
    }

    int maxSubArraySum(vector<int>& arr, int left, int right)
    {
        if (left == right)  
            return arr[left];

        int mid = (left + right) / 2;
        /* Return maximum of following three possible cases
        a) Maximum subarray sum in left half
        b) Maximum subarray sum in right half
        c) Maximum subarray sum such that the subarray crosses the midpoint */
        return std::max({maxSubArraySum(arr, left, mid),
                    maxSubArraySum(arr, mid+1, right),
                    maxCrossingSum(arr, left, mid, right)});
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
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().maxSubArray(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
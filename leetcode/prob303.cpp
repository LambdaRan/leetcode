

// https://leetcode.com/problems/range-sum-query-immutable/description/
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
/*
* Name: 303. Range Sum Query - Immutable
* Description: 
* Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
* 
* Example:
* Given nums = [-2, 0, 3, -5, 2, -1]
* sumRange(0, 2) -> 1
* sumRange(2, 5) -> -1
* sumRange(0, 5) -> -3
* 
* Note:
* You may assume that the array does not change.
* There are many calls to sumRange function.
* 
*/
class NumArray {
public:
    NumArray(vector<int> nums) 
    {
        int sum = 0;
        std::transform(nums.begin(), nums.end(), 
                    std::back_inserter(sum_),
                    [&](int value) {
                        return (sum += value);
                    });
    }
    
    int sumRange(int i, int j) {
        if (i == 0)
            return sum_[j];
        else  
            return sum_[j]-sum_[i-1];
    }
// public NumArray(int[] nums) {
//     sum = new int[nums.length + 1];
//     for (int i = 0; i < nums.length; i++) {
//         sum[i + 1] = sum[i] + nums[i];
//     }
// }

// public int sumRange(int i, int j) {
//     return sum[j + 1] - sum[i];
// }
private: 
    vector<int> sum_;
};


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */



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
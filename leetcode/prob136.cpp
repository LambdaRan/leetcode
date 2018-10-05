
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
* Name: 136. Single Number
* WebSite: https://leetcode.com/problems/single-number/description/
* Description: 
*
*/
class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    // 两个相同的数异或后为0
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int v : nums)
            result ^= v;
        return result;
    }
    // 其他方法： 
    // 使用hash{unordered_multimap}来存储<数值,出现次数>，然后遍历查找
    // 2∗(a+b+c)−(a+a+b+b+c)=c   return 2 * sum(set(nums)) - sum(nums)
    // 

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
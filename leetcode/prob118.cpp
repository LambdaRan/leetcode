
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
* Name: 118. Pascal's Triangle
* WebSite: https://leetcode.com/problems/pascals-triangle/description/
* Description: 
*
*/
class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    void create(vector<vector<int>>& result, vector<int>& top)
    {
        vector<int> newColumns(1,1);
        for (size_t i = 0; i < top.size()-1; ++i)
            newColumns.emplace_back(top[i]+top[i+1]);
        newColumns.emplace_back(1);
        result.emplace_back(newColumns);
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        switch (numRows)
        {
            case 0: 
                break;
            case 1: 
                result.emplace_back(vector<int>(1,1));
                break;
            case 2:
                result.emplace_back(vector<int>(1,1));
                result.emplace_back(vector<int>(2,1));
                break;
            default: 
            {
                result.emplace_back(vector<int>(1,1));
                result.emplace_back(vector<int>(2,1));
                for (int i = 2; i < numRows; ++i)
                    create(result, result.back());
            }
            break;
        }  
        return result;
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
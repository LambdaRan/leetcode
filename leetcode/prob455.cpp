
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
* Name: 455. Assign Cookies
* WebSite: https://leetcode.com/problems/assign-cookies/description/
* Description: 
*
*/
class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        size_t i = 0;
        for (int v : s) {
            if (i < g.size() && v >= g[i])
                ++i;
        }
        return i;
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
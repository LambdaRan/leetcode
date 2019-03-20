
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
* Name: 447. Number of Boomerangs
* WebSite: https://leetcode.com/problems/number-of-boomerangs/description/
* Description: 
*
*/
class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
   // 利用map存储当前点与其他点距离和个数，然后遍历map计算以此点组成boomerang的个数
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int ret = 0;
        int dist = 0;
        for (size_t i = 0; i < points.size(); ++i) {
            unordered_map<int, int> distMap(points.size());
            for (size_t j = 0; j < points.size(); ++j) {
                dist = pow(points[i].first - points[j].first, 2)
                    + pow(points[i].second - points[j].second, 2);
                ++distMap[dist];
            }
            for (auto &v : distMap) {
                ret += v.second * (v.second - 1);
            }
        }
        return ret;
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
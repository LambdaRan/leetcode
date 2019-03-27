
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <utility>

#include <cctype>

using namespace std;
/*
* Name: 463. Island Perimeter
* WebSite: https://leetcode.com/problems/island-perimeter/
* Description: 
*
*/
class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        std::sort(heaters.begin(), heaters.end());
        int radius = 0;
        int res = 0;
        for (int house : houses) {
            auto lbv = std::lower_bound(heaters.begin(), heaters.end(), house);
            radius = std::numeric_limits<int>::max();
            if (lbv != heaters.end()) {
                radius = *lbv - house;
            }
            radius = (i != heaters.begin() ? house - *(--lbv) : std::numeric_limits<int>::max());
            if (lbv != heaters.end()) {
                radius = min(radius, *lbv - house);
            }
            res = max(res, radius);
        }
        return res;
    }
};
        int maxRadius = 0;
        sort(heaters.begin(), heaters.end());
        for (const auto& house : houses) {
            int distance1 = INT_MAX;
            int distance2 = INT_MAX;
            auto larger = lower_bound(heaters.begin(), heaters.end(), house);
            if (larger != heaters.end())
                distance1 = *larger - house;
            if (larger != heaters.begin()) {
                auto smaller = larger - 1;
                distance2 = house - (*smaller);
            }
            maxRadius = max(maxRadius, min(distance1, distance2));
        }
        
        return maxRadius;
int main() 
{
    Solution s;

    std::cout << "method 1: \n";

    std::cout << std::endl;
    return 0;
}
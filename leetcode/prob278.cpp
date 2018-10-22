
#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <utility>
#include <iterator>
#include <string>
#include <vector>


using namespace std;
/*
* Name: 278. First Bad Version
* Website: https://leetcode.com/problems/first-bad-version/description/
* Description: 
*
*/
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);
class Solution
{
  public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    // 方法一： 线性查找 Time Limit Exceeded]
    // 方法二： 二分查找 
    int firstBadVersion(int n) {
        
        int low = 1;
        int high = n;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (isBadVersion(mid))
                high = mid - 1;
            else 
                low = mid + 1;
        }
        return low;
    }
};

int main()
{
    Solution s;

    std::cout << "method 1: \n";
    //std::cout <<  "function(): true <------> " << boolToString(s.function()) << "\n";

    std::cout << std::endl;
    return 0;
}
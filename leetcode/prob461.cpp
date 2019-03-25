
#include <iostream>
#include <algorithm>
#include <sstream>
#include <functional>
#include <utility>
#include <iterator>
#include <string>
#include <vector>
#include <bitset>

using namespace std;
/*
* Name: 461. Hamming Distance
* WebSite: https://leetcode.com/problems/hamming-distance/description/
* Description: 查看191题
*
*/
class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    int hammingDistance(int x, int y) {
        int count = 0;
        for (unsigned i = x ^ y; i > 0; i /= 2) {
            if (i & 1)
                ++count;
        }
        return count;
    }
    int hammingWeight_v1(int n) {
        int sum = 0;
        while (n != 0) {
            sum++;
            n &= (n - 1);
        }
        return sum;
    }
    int hammingWeight_v2(uint32_t n) {
        return bitset<32>(n).count();
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
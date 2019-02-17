
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
* Name: 443. String Compression
* WebSite: https://leetcode.com/problems/string-compression/description/
* Description: 
*
*/
class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    int compress(vector<char>& chars) {
        int sameCount = 1;
        size_t left = 0;
        size_t newLength = 0;
        for (size_t right = 1; right <= chars.size(); ++right) {
            if (right == chars.size() || chars[right] != chars[left]) {
                chars[newLength++] = chars[left];
                if (sameCount == 1) {
                    ++left;
                } else {
                    string counter = std::to_string(sameCount);
                    std::copy(counter.begin(), counter.end(), std::next(chars.begin(), newLength));
                    newLength += counter.size();
                    left = right;
                    sameCount = 1;
                }
            } else {
                ++sameCount;
            }
        }
        chars.erase(std::next(chars.begin(), newLength), chars.end());
        return newLength;
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
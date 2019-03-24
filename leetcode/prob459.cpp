
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
* Name: 459. Repeated Substring Pattern
* WebSite: https://leetcode.com/problems/repeated-substring-pattern/description/
* Description: 
*
*/
class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    bool repeatedSubstringPattern(string s) {
        if (s.size() < 2) return false;
        string ss = (s+s).substr(1, 2*s.size()-2);
        return ss.find(s) != string::npos;
    }
    bool repeatedSubstringPattern_v2(string s) {
        size_t sn = s.size();
        if (sn < 2) return false;
        bool ret = false;
        for (size_t i = 1; i <= sn/2; ++i) {
            if (sn % i) continue;
            string ss = s.substr(0, i);
            ret = true;
            for (size_t j = i; j < sn; j += i) {
                if (ss != s.substr(j, i)) {
                    ret = false;
                    break;
                }
            }
            if (ret) break;
        }
        return ret;
    }
    bool repeatedSubstringPattern_v3(string s) {
        size_t sn = s.size();
        if (sn < 2) return false;
        std::vector<int> next(sn+1, -1);
        size_t i = 0; 
        size_t j = -1;
        while (i < sn) {
            if (j == -1 || s[i] == s[j]) {
                next[++i] = ++j;
            } else {
                j = next[j];
            }
        }
        return (next[sn] && next[sn]%(sn-next[sn])==0);
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
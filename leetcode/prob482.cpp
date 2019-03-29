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
    string licenseKeyFormatting(string S, int K) {
        string res = "";
        int cn = 0;
        for (int i = static_cast<int>(S.size())-1; i != -1; --i) {
            if (S[i] != '-') {
                res += std::toupper(S[i]);
                if (++cn == K) {
                    res += '-';
                    cn = 0;
                }
            }
        }
        if (!res.empty() && res.back() == '-')
            res.pop_back();
        std::reverse(res.begin(), res.end());
        return res;
    } 
};

int main() 
{
    Solution s;

    std::cout << "method 1: \n";

    std::cout << std::endl;
    return 0;
}                
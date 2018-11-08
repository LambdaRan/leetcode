
#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <utility>
#include <iterator>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;
/*
* Name: 389. Find the Difference
* Website: https://leetcode.com/problems/find-the-difference/description/
* Description: 
*
*/
class Solution
{
  public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    char findTheDifference(string s, string t) {
        if (s.empty()) return t[0];
        vector<int> sCount('z'-'a'+1, 0);
        for (char v : s)
            ++sCount[v-'a'];
        char result;
        for (char v : t)
        {
            if (--sCount[v-'a'] < 0)
                return v;
            if (sCount[v-'a'] > 0)  
                result = v;
        }
        return result;
    }
    char findTheDifference(string s, string t) {
        if (s.empty()) return t[0];
        char result = 0;
        for (char v : s) result ^= v;
        for (char v : t) result ^= v;
        return result;
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
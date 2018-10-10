
#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <utility>
#include <iterator>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
/*
* Name: 205. Isomorphic Strings
* Website: https://leetcode.com/problems/isomorphic-strings/description/
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
    bool isIsomorphic(string s, string t) {
        if (s.empty() && t.empty()) return true;
        vector<int> one(256, -1);
        vector<int> two(256, -1);
        for (int i = 0; i < static_cast<int>(s.size()); ++i)
        {
            if (one[s[i]] != two[t[i]]) return false;
            one[s[i]] = i;
            two[t[i]] = i;
        }        
        return true;
    }
    
    bool isIsomorphic_v1(string s, string t) {
        unordered_map<char, int> oneIndex;
        vector<int> oneSeque(s.size());
        for (int i = 0; i < static_cast<int>(s.size()); ++i)
        {
            if (oneIndex.find(s[i]) == oneIndex.end())
            {
                oneIndex[s[i]] = i;
                oneSeque[i] = i;
            }
            else  
            {
                oneSeque[i] = oneIndex[s[i]];
            }
        }

        unordered_map<char, int> twoIndex;
        vector<int> twoSeque(s.size());
        for (int i = 0; i < static_cast<int>(t.size()); ++i)
        {
            if (twoIndex.find(t[i]) == twoIndex.end())
            {
                twoIndex[t[i]] = i;
                twoSeque[i] = i;
            }
            else  
            {
                twoSeque[i] = twoIndex[t[i]];
            }
            if (twoSeque[i] != oneSeque[i])
                return false;
        }
        return true;
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
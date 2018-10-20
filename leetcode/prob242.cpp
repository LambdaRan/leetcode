
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
* Name: 242. Valid Anagram
* Website: https://leetcode.com/problems/valid-anagram/description/
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
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int> one('z'-'a', 0);
        for (char ch : s)
            ++one[ch-'a'];
        for (char ch : t)
            --one[ch-'a'];
        return std::find_if(one.begin(), one.end(), [](const int v){
            return v != 0;
        }) == one.end();
    }
    bool isAnagram_v2(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> one;
        for (char ch : s)
            ++one[ch];
        
        for (char ch : t)
        {
            if (one.find(ch) == one.end())
                return false;
            else 
            {
                if (one[ch] == 0)
                    return false;
                --one[ch];
            }
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
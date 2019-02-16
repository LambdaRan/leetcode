
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
* Name: 438. Find All Anagrams in a String
* Website: https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
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
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (s.size() < p.size()) return result;
        vector<int> pMap('z'-'a'+1, 0);
        for (auto v : p) pMap[v - 'a']++;
        size_t count = p.size();
        size_t left = 0;
        size_t right = 0;
        while (right < s.size()) {
            if (pMap[s[right++] - 'a']-- > 0) --count;
            if (count == 0) result.emplace_back(left);

            if (right - left == p.size() && pMap[s[left++] - 'a']++ >= 0)
                ++count;            
        }
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
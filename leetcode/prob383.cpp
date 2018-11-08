
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
* Name: 383. Ransom Note
* Website: https://leetcode.com/problems/ransom-note/description/
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
    bool canConstruct(string ransomNote, string magazine) {
        if (magazine.empty()) return ransomNote.empty();
        vector<int> magaCharCount('z'-'a'+1, 0);
        for (auto& v : magazine)
            ++magaCharCount[v-'a'];
        for (auto& v : ransomNote)
        {
            if (magaCharCount[v-'a'] > 0)
                --magaCharCount[v-'a'];
            else 
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
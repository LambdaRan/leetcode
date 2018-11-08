
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
* Name: 387. First Unique Character in a String
* Website: https://leetcode.com/problems/first-unique-character-in-a-string/description/
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
    int firstUniqChar(string s) {
        if (s.empty()) return -1;
        vector<int> letterCount('z'-'a'+1, 0);
        for (char v : s)
            ++letterCount[v-'a'];
        for (size_t i = 0; i < s.size(); ++i)
        {
            if (letterCount[s[i]-'a'] == 1)
                return i;
        }
        return -1;
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

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
* Name: 290. Word Pattern
* Website: https://leetcode.com/problems/word-pattern/description/
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
    bool wordPattern(string pattern, string str) {
        
        std::unordered_map<char, int> letterMap;
        std::unordered_map<string, int> wordsMap;
        std::istringstream words(str);
        int i = 0, n = static_cast<int>(pattern.size());
        for (string word; words >> word; ++i)
        {
            if (i == n || letterMap[pattern[i]] != wordsMap[word])
                return false;
            letterMap[pattern[i]] = wordsMap[word] = i + 1;
        }
        return i == n;
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
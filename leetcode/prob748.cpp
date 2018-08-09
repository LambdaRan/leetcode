
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <utility>

#include <cctype>

using namespace std;
/*
* Name: 748. Shortest Completing Word
* Description: 
*
*/
class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    string shortestCompletingWord(string licensePlate, vector<string>& words) 
    {
        std::vector<int> letters(27);
        int letterCount = 0;
        for (char ch : licensePlate)
        {
            if (std::isalpha(ch))
            {
                ++letters[std::tolower(ch) - 'a'];
                ++letterCount;
            }
        }
        std::string result = "";
        for (const string& word : words)
        {
            int curWordCount = letterCount;
            std::vector<int> curWordLetters(letters);
            for (char ch : word)
            {
                if (curWordLetters[std::tolower(ch) - 'a']-- > 0)
                    --curWordCount;
                if (curWordCount == 0) break;
            }
            if (curWordCount == 0 && (result.empty() || result.size() > word.size()))
                result = word;
        }
        return result;
    }
};
int main() 
{
    Solution s;

    std::cout << "method 1: \n";

    std::cout << std::endl;
    return 0;
}
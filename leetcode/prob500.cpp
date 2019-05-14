
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <iterator>
#include <unordered_map>

#include <cctype>

using namespace std;
/*
* Name: 500. Keyboard Row
* WebSite: https://leetcode.com/problems/keyboard-row/
* Description: 
*
*/
class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    vector<string> findWords(vector<string>& words) {
        vector<string> alphabet = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        unordered_map<char, int> alphaToRows;
        for (size_t i = 0; i < alphabet.size(); ++i) {
            const string &alpha = alphabet[i];
            for (const auto v : alpha) {
                alphaToRows[v] = static_cast<int>(i);
            }
        }

        bool isOnlyOneRows = true; 
        vector<string> result;
        for (const auto &word : words) {
            if (!word.empty()) {
                isOnlyOneRows = true;
                for (size_t i = 0; i < word.size(); ++i) {
                    if (alphaToRows[std::tolower(word[0])] != alphaToRows[std::tolower(word[i])]) {
                        isOnlyOneRows = false;
                        break;
                    }
                }
                if (isOnlyOneRows)
                    result.emplace_back(word);
                // char first = word[0];
                // if (std::all_of(word.begin(), word.end(), [&alphaToRows, first](char w) {
                //     return alphaToRows[std::tolower(first)] == alphaToRows[std::tolower(w)];
                // })) {
                //     result.emplace_back(word);
                // } 
            }
        }
        return result;
    }
};

int main() 
{
    Solution s; 


    std::cout << "method 1: \n";
    vector<string> test = {"Hello", "Alaska", "Dad", "Peace"};
    auto ret = s.findWords(test);
    std::cout << std::endl;
    return 0;
}                
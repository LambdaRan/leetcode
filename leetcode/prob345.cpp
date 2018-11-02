
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
* Name: 345. Reverse Vowels of a String
* Website: https://leetcode.com/problems/reverse-vowels-of-a-string/description/
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
    string reverseString_v1(string s) {
        int startIndex = 0;
        int endIndex = static_cast<int>(s.size()) -1;
        // unordered_set<char> vowrls = {'a','e','i','o','u','A','E','I','O','U'};
        // while (startIndex < endIndex)
        // {
        //     while (startIndex < endIndex && vowrls.find(s[startIndex]) == vowrls.end())
        //         ++startIndex;
        //     //cout << s[startIndex] << endl;
        //     while (startIndex < endIndex && vowrls.find(s[endIndex]) == vowrls.end())
        //         --endIndex;
        //     //cout << s[endIndex] << endl;
        //     if (!(startIndex < endIndex)) break;
        //     swap(s[startIndex++], s[endIndex--]);
        // }
        vector<bool> vowels(128, false);
        vowels['a'] = vowels['e'] = vowels['i'] = vowels['o'] = vowels['u'] = true;
        vowels['A'] = vowels['E'] = vowels['I'] = vowels['O'] = vowels['U'] = true;
        while (startIndex < endIndex)
        {
            while (startIndex < endIndex && vowels[s[startIndex]] == false)
                ++startIndex;
            //cout << s[startIndex] << endl;
            while (startIndex < endIndex && vowels[s[endIndex]] == false)
                --endIndex;
            //cout << s[endIndex] << endl;
            if (!(startIndex < endIndex)) break;
            swap(s[startIndex++], s[endIndex--]);
        }
        return s;
    }
    string reverseVowels_v1(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            i = s.find_first_of("aeiouAEIOU", i);
            j = s.find_last_of("aeiouAEIOU", j);
            if (i < j) {
                swap(s[i++], s[j--]);
            }
        }
        return s;
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
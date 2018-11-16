
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
* Name: 409. Longest Palindrome
* Website: https://leetcode.com/problems/longest-palindrome/description/
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
    int longestPalindrome(string s) {
        if (s.empty()) return 0;
        vector<int> letterCount(128, 0);
        for (auto& v : s)
            ++letterCount[v-'A'];
        int longest = 0;
        for (int i = 0; i < letterCount.size(); ++i)
        {
            if (letterCount[i] > 0)
            {
                longest += (letterCount[i]>>1) << 1;
                longest |= letterCount[i]&0x01;
            }
        }
        return longest;
        // int longest = 0;
        // bool hasOdd = false;
        // for (int i = 0; i < letterCount.size(); ++i)
        // {
        //     if (letterCount[i] > 0)
        //     {
        //         if (letterCount[i] & 0x01)
        //         {
        //             longest += letterCount[i] - 1;
        //             hasOdd = true;
        //         }
        //         else 
        //             longest += letterCount[i];
        //     }
        // }
        // return hasOdd ? (longest+1) : longest;
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

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
* Name: 344. Reverse String
* Website: https://leetcode.com/problems/reverse-string/description/
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
    string reverseString(string s) {
        if (s.empty()) return s;
        std::reverse(s.begin(), s.end());
        return s;
    }
    string reverseString_v1(string s) {
        int startIndex = 0;
        int endIndex = static_cast<int>(s.size()) -1;
        while (startIndex < endIndex)
            swap(s[startIndex++], s[endIndex--]);
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
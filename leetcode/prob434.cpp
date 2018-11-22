
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
* Name: 434. Number of Segments in a String
* Website: https://leetcode.com/problems/number-of-segments-in-a-string/description/
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
    int countSegments(string s) {
        if (s.empty()) return 0;
        bool last_is_space = true;
        int segs = 0;
        for(char c: s)
        {
            bool this_is_space = (c == ' ');
            segs += last_is_space&!this_is_space;
            last_is_space = this_is_space;
        }
        return segs;
    }
    int countSegments_v1(string s) {
        if (s.empty()) return 0;
        istringstream allWords(s);
        string word;
        int count = 0;
        while (allWords >> word)
            ++count;
        return count;
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
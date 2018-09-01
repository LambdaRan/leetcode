

#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <utility>
#include <iterator>
#include <string>
#include <vector>

using namespace std;
/*
* Name: 
* Description: 
*
*/
class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    int lengthOfLastWord(string s) {
        if (s.empty()) return 0;

        int start = static_cast<int>(s.size()) - 1;
        while (start >= 0 && s[start] == ' ') --start;
        if (start < 0) return 0;
        int second = start;
        while (second >= 0 && s[second] != ' ') --second;
        return start - second;
    }

    int lengthOfLastWord_v1(string s) 
    {
        if (s.empty()) return 0;
        s.erase(s.find_last_not_of(" ")+1);
        auto ret = s.rfind(' ');
        return distance(next(s.begin(), ret+1), s.end());
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
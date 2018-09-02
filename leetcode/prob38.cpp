

// https://leetcode.com/problems/count-and-say/description/
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
* Name: 38. Count and Say
* Description: 
*
*/
class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    string countAndSay(int n) 
    {
        string result;
        if (n == 0) return result;
        result = "1";
        for (int k = 2; k <= n; ++k)
        {
            string cur = "";
            size_t first = 0;
            size_t second = 1;
            while (second < result.size())
            {
                if (result[second] != result[first])
                {
                    int cnt = second - first;
                    cur += cnt + '0';
                    cur += result[first];
                    first = second;
                }
                ++second;
            }
            if (first < second)
            {
                int cnt = second - first;
                cur += cnt + '0';
                cur += result[first];
            }
            result = cur;
        }
        return result;
    }
};
std::string boolToString(bool input) {
    return input ? "True" : "False";
}
int main() 
{
    Solution s;

    std::cout << "method 1: \n";
    //std::cout <<  "function(): true <------> " << boolToString(s.function()) << "\n";

    std::cout << std::endl;
    return 0;
}

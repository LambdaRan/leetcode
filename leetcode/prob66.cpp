

// https://leetcode.com/problems/plus-one/description/
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
* Name: 66. Plus One
* Description: 
*
*/
class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    vector<int> plusOne(vector<int>& digits) 
    {
        int index = static_cast<int>(digits.size());
        int remain = 1;
        for (int i = index-1; i >= 0; --i)
        {
            if (digits[i] == 9)
            {
                digits[i] = 0;
            }
            else  
            {
                ++digits[i];
                remain = 0;
                break;
            }
        }
        if (remain)
        {
            vector<int> result;
            result.push_back(1);
            result.insert(result.end(), digits.begin(), digits.end());
            return result;
        }
        return digits;
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
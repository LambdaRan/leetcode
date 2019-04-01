
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <iterator>

#include <cctype>

using namespace std;
/*
* Name: 496. Next Greater Element I
* WebSite: https://leetcode.com/problems/next-greater-element-i/
* Description: 
*
*/
class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_map<int, int> valueGreater = {};
        std::vector<int> stack = {};
        for (int v : nums2) {
            while (!stack.empty() && v > stack.back()) {
                valueGreater[stack.back()] = v;
                stack.pop_back();
            }
            stack.push_back(v);
        }
        std::vector<int> res = {};
        for (int v : nums1) {
            int greater = valueGreater[v];
            if (greater == 0)
                res.emplace_back(-1);
            else 
                res.emplace_back(greater);
        }
        return res;
    }
};

int main() 
{
    Solution s; 


    std::cout << "method 1: \n";

    std::cout << std::endl;
    return 0;
}                
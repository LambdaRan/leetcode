
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <utility>
#include <iterator>
#include <unordered_map>

#include <cctype>

using namespace std;
/*
* Name: 501. Find Mode in Binary Search Tree
* WebSite: https://leetcode.com/problems/find-mode-in-binary-search-tree/
* Description: 
*
*/
class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
   // 此方案不正确，不是O(1)空间复杂度
    vector<int> findMode(TreeNode *root)
    {
        stack<TreeNode*> stk;
        TreeNode *cur = root;
        int maxCount = 0;
        std::unordered_map<int, int> valueCounts;
        while (cur != nullptr || !stk.empty()) {
            while (cur != nullptr) {
                ++valueCounts[cur->val];
                maxCount = std::max(maxCount, valueCounts[cur->val]); 
                stk.push(cur);
                cur = cur->left;
            }
            if (!stk.empty()) {
                cur = stk.top();
                stk.pop();
                cur = cur->right;
            }
        }
        vector<int> result;
        for (const auto &v : valueCounts) {
            if (maxCount == v.second)
                result.emplace_back(v.first);
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
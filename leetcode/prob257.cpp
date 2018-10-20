
#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <utility>
#include <iterator>
#include <string>
#include <vector>
#include <stack>

using namespace std;
/*
* Name: 257. Binary Tree Paths
* Website: https://leetcode.com/problems/binary-tree-paths/description/
* Description: 
*
*/
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
  public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (!root) return result;
        
        stack<TreeNode*> sk;
        TreeNode* cur = root;
        TreeNode* prev = nullptr;
        vector<string> rootToLeaf;
        while (cur || !sk.empty())
        {
            while (cur)
            {
                rootToLeaf.emplace_back(to_string(cur->val));
                rootToLeaf.emplace_back("->");  
                sk.push(cur);
                cur = cur->left;
            }
            cur = sk.top();
            if (cur->left == nullptr && cur->right == nullptr)
            {
                string ones;
                for(auto it = rootToLeaf.begin(); it != rootToLeaf.end()-1; ++it)
                    ones += *it;
                result.emplace_back(ones);
            }
            
            if (cur->right == nullptr || cur->right == prev)
            {
                sk.pop();
                prev = cur;
                cur = nullptr;
                rootToLeaf.erase(rootToLeaf.end()-2, rootToLeaf.end());
            }
            else 
            {
                cur = cur->right;
            }
        }
        return result;
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

#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <utility>
#include <iterator>
#include <string>
#include <vector>
#include <queue>

using namespace std;
/*
* Name: 226. Invert Binary Tree
* Website: https://leetcode.com/problems/invert-binary-tree/description/
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
    // Eratosthenes筛选算法
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        std::swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
    TreeNode* invertTree_v2(TreeNode* root) {
        if (!root) return root;
        std::queue<TreeNode*> tree;
        tree.push(root);
        while (!tree.empty())
        {
            TreeNode* cur = tree.front();
            tree.pop();
            std::swap(cur->left, cur->right);
            if (cur->left) tree.push(cur->left);
            if (cur->right) tree.push(cur->right);
        }
        return root;
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
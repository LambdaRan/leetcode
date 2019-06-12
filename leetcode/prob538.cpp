
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <utility>
#include <iterator>
#include <unordered_set>
#include <cmath>
#include <cctype>
#include <limits>
#include <functional>

#include "gtest/gtest.h"

using namespace std;
using std::placeholders::_1;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
* Name: 530. Minimum Absolute Difference in BST
* WebSite: https://leetcode.com/problems/minimum-absolute-difference-in-bst/
* Description: 
*
*/
class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    TreeNode* convertBST_v1(TreeNode* root) {
        if (root == NULL) return root;
        int sum = 0;
        TreeNode *cur = root;
        std::stack<TreeNode *> stk;
        while (cur || !stk.empty()) {
            while (cur)
            {
                stk.push(cur);
                cur =  cur->right;
            }
            if (!stk.empty()) {
                cur = stk.top();
                stk.pop();
                cur->val += sum;
                sum = cur->val;
                cur = cur->left;
            }
        }
        return root;
    }
    void helper(TreeNode *node, int &sum)
    {
        if (node) {
            helper(node->right, sum);
            node->val += sum;
            sum = node->val;
            helper(node->left, sum);
        }
    }
    TreeNode* convertBST_v2(TreeNode* root) {
        if (root == NULL) return root;
        int sum = 0;
        helper(root, sum);
        return root;
    }
    
    TreeNode* convertBST_v1(TreeNode* root) {
        if (root == NULL) return root;
        int sum = 0;
        // 中序遍历求和
        TreeNode *cur = root;
        std::stack<TreeNode *> stk;
        while (cur || !stk.empty()) {
            while (cur)
            {
                stk.push(cur);
                cur =  cur->left;
            }
            if (!stk.empty()) {
                cur = stk.top();
                stk.pop();
                sum += cur->val;
                cur = cur->right;
            }
        }
        int preVal = 0;
        int tmpVal = 0;
        cur = root;
        while (cur || !stk.empty()) {
            while (cur)
            {
                stk.push(cur);
                cur =  cur->left;
            }
            if (!stk.empty()) {
                cur = stk.top();
                stk.pop();
                tmpVal = cur->val;
                cur->val = sum - preVal;
                preVal += tmpVal;
                cur = cur->right;
            }
        }
        return root;
    }
};

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}


Solution solu; 

TEST(DetectCapitalUseTest, Positive) 
{
    //EXPECT_EQ(solu);

}

              
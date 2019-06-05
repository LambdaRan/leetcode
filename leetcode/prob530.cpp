
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

#include "gtest/gtest.h"

using namespace std;

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
    int getMinimumDifference(TreeNode* root) {
        // 中序遍历，统计相邻间数值之差
        TreeNode *cur = root;
        std::stack<TreeNode *> stk;
        int absMin = std::numeric_limits<int>::max();
        int preValue = std::numeric_limits<int>::max();
        while (cur || !stk.empty()) {
            while (cur) {
                stk.push(cur);
                cur = cur->left;
            }
            if (!stk.empty()) {
                cur = stk.top();
                stk.pop();
                absMin = std::min(absMin, std::abs(cur->val-preValue));
                preValue = cur->val;
                cur = cur->right;
            }
        }
        return absMin; 
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
    EXPECT_TRUE(solu.detectCapitalUse("Hello"));
    EXPECT_TRUE(solu.detectCapitalUse("world"));
    EXPECT_TRUE(solu.detectCapitalUse("LAMBDA"));

    EXPECT_FALSE(solu.detectCapitalUse("LeetCode"));
    EXPECT_FALSE(solu.detectCapitalUse("rAn"));
}

              
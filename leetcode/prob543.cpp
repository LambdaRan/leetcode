#include <iostream>
#include <stack>
#include <queue>

#include "gtest/gtest.h"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
* Name: 543. Diameter of Binary Tree
* WebSite: https://leetcode.com/problems/diameter-of-binary-tree/
* Description:
*
*/

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        helper(root, diameter);
        return diameter;
    }
    int helper(TreeNode* root, int& max) {
        if (root == nullptr) {
            return -1;
        }
        int left = helper(root->left, max);
        int right = helper(root->right, max);
        int diameter = 0;
        if (root->left) {
            diameter += left + 1;
        }
        if (root->right) {
            diameter += right + 1;
        }
        max = max > diameter ? max : diameter;
        return left > right ? left+1 : right+1;
    }
};


void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

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

void freeTreeNode(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    freeTreeNode(root->left);
    freeTreeNode(root->right);
    if (root) {
        delete root;
    }
    root = nullptr;
}

Solution solu;

TEST(diameterOfBinaryTree, One)
{
    string line = "[1,2,3,4,5]";
    TreeNode* root = stringToTreeNode(line);
    EXPECT_EQ(solu.diameterOfBinaryTree(root), 3);
    freeTreeNode(root);
}

TEST(diameterOfBinaryTree, Two)
{
    string line = "[1,2]";
    TreeNode* root = stringToTreeNode(line);
    EXPECT_EQ(solu.diameterOfBinaryTree(root), 1);
    freeTreeNode(root);
}

TEST(diameterOfBinaryTree, Three)
{
    string line = "[1,2,3,4,5,null,null,6]";
    TreeNode* root = stringToTreeNode(line);
    EXPECT_EQ(solu.diameterOfBinaryTree(root), 4);
    freeTreeNode(root);
}

#include <iostream>
#include <string>
#include <vector>
#include <stack>

#include "gtest/gtest.h"

using namespace std;

// Name: 572. Subtree of Another Tree
// Website: https://leetcode.com/problems/subtree-of-another-tree/
// Description:

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool node_equal(TreeNode *s, TreeNode *t) {
        if (s == nullptr && t == nullptr) return true;
        if (s == nullptr || t == nullptr) return false;
        if (s->val != t->val) return false;
        return node_equal(s->left,t->left) && node_equal(s->right,t->right);
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == nullptr && t == nullptr) return true;
        if (s == nullptr || t == nullptr) return false;
        return node_equal(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }

};

Solution solu;

// TEST(Fuction, one) {}

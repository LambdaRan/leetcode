#include <iostream>
#include <string>

#include "gtest/gtest.h"

using namespace std;

// Name: 563. Binary Tree Tilt
// Website: https://leetcode.com/problems/binary-tree-tilt/
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
    int findTilt(TreeNode* root) {
        if (nullptr == root) return 0;
        int tilt = 0;
        helper(root, tilt);
        return tilt;
    }

    int helper(TreeNode* root, int& tilt) {
        if (nullptr == root) return 0;
        int lc = helper(root->left, tilt);
        int rc = helper(root->right, tilt);
        int ret = lc > rc ? lc - rc : rc - lc;
        tilt += ret;
        return lc + rc + root->val;
    }

};

Solution solu;

// TEST(Fuction, one) {}
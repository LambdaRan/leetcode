#include <iostream>
#include <string>

#include "gtest/gtest.h"

using namespace std;

// Name: 617. Merge Two Binary Trees
// Website: https://leetcode.com/problems/merge-two-binary-trees/
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
    TreeNode *mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr) return t2;
        std::vector<std::pair<TreeNode*, TreeNode*>> stk;
        stk.emplace_back(t1, t2);
        while (!stk.empty()) {
            auto cur = stk.back();
            stk.pop_back();
            if (cur.first == nullptr || cur.second == nullptr) continue;
            cur.first->val += cur.second->val;
            if (cur.first->left == nullptr) {
                cur.first->left = cur.second->left;
            } else {
                stk.emplace_back(cur.first->left, cur.second->left);
            }
            if (cur.first->right == nullptr) {
                cur.first->right = cur.second->right;
            } else {
                stk.emplace_back(cur.first->right, cur.second->right);
            }
        }
    }


    TreeNode * mergeTrees_v2(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr) return t2;
        if (t2 == nullptr) return t1;
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1;
    }
    TreeNode* mergeTrees_v1(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr) return nullptr;
        if (t1 != nullptr) {
            if (t2 != nullptr) {
                t1->val += t2->val;
                merge(t1, t1->left, t2, t2->left, true);
                merge(t1, t1->right, t2, t2->right, false);
            }
            return t1;
        }
        return t2;
    }

    void merge(TreeNode* parent_left, TreeNode* left, TreeNode* parent_right, TreeNode* right, bool is_left) {
        if (left == nullptr && right == nullptr) return;
        if (left != nullptr) {
            if (right != nullptr) {
                left->val += right->val;
                merge(left, left->left, right, right->left, true);
                merge(left, left->right, right, right->right, false);
            }
        } else {
            if (is_left) {
                parent_left->left = right;
                parent_right->left = nullptr;
            } else {
                parent_left->right = right;
                parent_right->right = nullptr;
            }
        }
    }

};

Solution solu;

// TEST(Fuction, one) {}
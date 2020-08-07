#include <iostream>
#include <string>

#include "gtest/gtest.h"

using namespace std;

// Name: 606. Construct String from Binary Tree
// Website: https://leetcode.com/problems/construct-string-from-binary-tree/
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

    string tree2str(TreeNode* t) {
        std::string result;
        if (t != nullptr) {
            helper(t, result);
            if (!result.empty() && result[0] == '(') {
                return result.substr(1, result.size()-2);
            }
        }
        return result;
    }
    void helper(TreeNode* t, std::string& str) {
        str += "(";
        str += std::to_string(t->val);
        if (t->left == nullptr) {
            if (t->right != nullptr) {
                str += "()";
            }
        } else {
            helper(t->left, str);
        }

        if (t->right != nullptr) {
            helper(t->right, str);
        }

        str += ")";
    }


    string tree2str_v2(TreeNode* t) {
        if (t == nullptr)
            return "";
        if (t->left == nullptr && t->right == nullptr)
            return std::to_string(t->val);
        if (t->right == nullptr)
            return std::to_string(t->val) + '(' + tree2str_v2(t->left) + ')';
        return std::to_string(t->val) + "(" + tree2str_v2(t->left) + ")(" + tree2str_v2(t->right) + ")";
    }

    string tree2str_v3(TreeNode* t) {
        if (t == nullptr) return "";
        std::vector<TreeNode*> stk;
        std::unordered_set<TreeNode*> visited;
        stk.push_back(t);
        std::string result;
        while (!stk.empty()) {
            TreeNode* cur = stk.back();
            if (visited.find(cur) != visited.end()) {
                stk.pop_back();
                result += ")";
            } else {
                visited.insert(cur);
                result += "(" + std::to_string(t->val);

                if (cur->left == nullptr && cur->right != nullptr) {
                    result += "()";
                }

                if (cur->right != nullptr) {
                    stk.emplace_back(cur->right);
                }

                if (cur->left != nullptr) {
                    stk.emplace_back(cur->left);
                }
            }
        }
        return result.substr(1, result.size()-2);
    }
};

Solution solu;

// TEST(Fuction, one) {}
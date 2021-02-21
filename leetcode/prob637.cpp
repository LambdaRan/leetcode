#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#include "gtest/gtest.h"

using namespace std;

// Name: 637. Average of Levels in Binary Tree
// Website: https://leetcode.com/problems/average-of-levels-in-binary-tree/
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
    vector<double> averageOfLevels(TreeNode* root) {
        std::vector<double> results;
        if (!root) return results;
        std::queue<TreeNode *> q;
        q.push(root);
        int count = 0;
        int level_count = 1;
        int64_t level_sum = 0;
        while (!q.empty()) {
            TreeNode* cur = q.front(); q.pop();
            level_sum += cur->val;
            if (cur->left) {
                q.push(cur->left);
            }
            if (cur->right) {
                q.push(cur->right);
            }
            ++count;
            if (count == level_count) {
                count = 0;
                double avg = static_cast<double>(level_sum) / level_count;
                results.emplace_back(avg);
                level_sum = 0;
                level_count = q.size();
            }
        }
        return results;
    }

    vector<double> averageOfLevels_v2(TreeNode* root) {
        std::vector<double> results;
        if (!root) return results;
        std::queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            size_t level_count = q.size();
            int64_t level_sum = 0;
            for (size_t i = 0; i < level_count; ++i) {
                TreeNode* cur = q.front(); q.pop();
                level_sum += cur->val;
                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }
            }
            results.emplace_back(static_cast<double>(level_sum)/level_count);
        }
        return results;
    }

};

Solution solu;

// TEST(Fuction, one) {}
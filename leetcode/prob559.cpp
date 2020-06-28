#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

#include "gtest/gtest.h"

using namespace std;

// Name: 559. Maximum Depth of N-ary Tree
// Website: https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
// Description:

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
  public:
    int maxDepth(Node* root) {
        if (root == nullptr) return 0;
        std::queue<Node*> que;
        que.push(root);
        uint32_t depth = 0;
        while (!que.empty()) {
            ++depth;
            for (uint32_t cur_level_size = 0; cur_level_size < que.size(); ++cur_level_size) {
                Node* node = que.front();
                que.pop();
                for (Node* child : node->children) {
                    que.push(child);
                }
            }
        }
        return depth;
    }

    // 深度优先遍历
    void dfs(Node* root, int cur_depth, int max_depth) {
        max_depth = std::max(max_depth, cur_depth);
        if (root == nullptr) return;
        for(auto& child : root->children){
            dfs(child, cur_depth + 1);
        }
    }

    int maxDepth2(Node* root) {
        if (root == nullptr) return 0;
        int depth = 0;
        int cur = 1;
        dfs(root, cur, depth);
        return depth;
    }

    // 深度优先遍历
    int maxDepth3(Node* root) {
        if (root == nullptr) return 0;
        int max_depth = 0;
        for (Node* child : root->children) {
            int cur_depth = maxDepth3(child);
            if (cur_depth > max_depth)
                max_depth = cur_depth;
        }
        return max_depth + 1;
    }
};

Solution solu;

// TEST(Fuction, one) {}
#include <iostream>
#include <string>

#include "gtest/gtest.h"

using namespace std;

// Name: 589. N-ary Tree Preorder Traversal
// Website: https://leetcode.com/problems/n-ary-tree-preorder-traversal/
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
    vector<int> preorder(Node* root) {
        std::vector<int> val;
        if (nullptr == root) return val;
        std::stack<Node*> stk;
        stk.push(root);
        while (!stk.empty()) {
            Node* node = stk.top();
            stk.pop();
            val.emplace_back(node->val);
            for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
                stk.push(*it);
            }
        }
        return val;
    }
};

Solution solu;

// TEST(Fuction, one) {}
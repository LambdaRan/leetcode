#include <iostream>
#include <string>

#include "gtest/gtest.h"

using namespace std;

// Name: 590. N-ary Tree Postorder Traversal
// Website: https://leetcode.com/problems/n-ary-tree-postorder-traversal/
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

    vector<int> postorder(Node* root) {
        std::vector<int> val;
        if (root == nullptr) return val;
        std::stack<Node*> stk;
        stk.push(root);
        while (!stk.empty()) {
            Node* node = stk.top();
            stk.pop();
            val.emplace_back(node->val);
            for (auto& child : node->children) {
                stk.push(child);
            }
        }
        std::reverse(val.begin(), val.end());
        return val;
    }

};

Solution solu;

// TEST(Fuction, one) {}
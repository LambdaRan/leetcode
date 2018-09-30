
#include <iostream>
#include <algorithm>
#include <sstream>
#include <functional>
#include <utility>
#include <vector>
#include <string>
#include <stack>
#include <queue>

//#include <stdio.h>

using namespace std;


/*
* Name: 107. Binary Tree Level Order Traversal II
* Website: https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
* Description: 
*
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        vector<vector<int>> result;
        if (!root) return result;
        queue<TreeNode*> q;
        q.push(root);
        size_t count = 0;
        size_t levelCount = 1;
        vector<int> levelVector;
        while (!q.empty())
        {
            TreeNode* cur = q.front();
            q.pop();
            levelVector.emplace_back(cur->val);
            ++count;
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
            if (count == levelCount)
            {
                count = 0;
                levelCount = q.size();
                result.emplace_back(levelVector);
                levelVector.clear();
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() 
{
    string line;
    while (getline(cin, line)) {
        // ListNode* head = stringToListNode(line);
        // getline(cin, line);
        // int n = stringToInteger(line);
        
        // //ListNode* ret = Solution().removeNthFromEnd(head, n);

        // string out = listNodeToString(ret);
        //cout << out << endl;
    }
    return 0;
}

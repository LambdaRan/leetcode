
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
* Name: 112. Path Sum
* Website: https://leetcode.com/problems/path-sum/description/
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
    bool hasPathSum(TreeNode* root, int sum) {
        // 后序遍历
        if (root == nullptr) return false;
        int curSum = 0;
        stack<TreeNode*> tnsk;
        TreeNode* prev = nullptr;
        TreeNode* cur = root;
        while (cur || !tnsk.empty())
        {
            while (cur)
            {
                curSum += cur->val;
                tnsk.push(cur);
                cur = cur->left;
            }
            cur = tnsk.top();
            if (!cur->left && !cur->right && curSum == sum)
                return true;
            if (cur->right == nullptr || cur->right == prev) 
            {
                curSum -= cur->val;
                prev = cur;
                tnsk.pop();
                cur = nullptr;
            }
            else  
                cur = cur->right;
        }
        return false;
    }
    bool hasPathSum_recursive(TreeNode* root, int sum) {
        if(root == nullptr) return false;
    
        if(root->left == nullptr && 
           root->right == nullptr && 
           sum - root->val == 0) return true;
    
        return hasPathSum_recursive(root->left, sum - root->val) || 
               hasPathSum_recursive(root->right, sum - root->val);
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


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
* Name: 101. Symmetric Tree
* Website: https://leetcode.com/problems/symmetric-tree/description/
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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> tnq;
        tnq.push(root);
        tnq.push(root);
        while (!tnq.empty())
        {
            TreeNode* n1 = tnq.front();
            tnq.pop();
            TreeNode* n2 = tnq.front();
            tnq.pop();

            if (!n1 && !n2) continue;
            if (!n1 || !n2) return false;
            if (n1->val != n2->val) return false;
            tnq.push(n1->left);
            tnq.push(n2->right);
            tnq.push(n1->right);
            tnq.push(n2->left);
        }
        return true;
    }
    bool isSymmetric_v1(TreeNode* root) {
        if (root == nullptr) return true;
        return _isSymmetric(root->left, root->right);
    }
    bool _isSymmetric(TreeNode* lt, TreeNode* rt)
    {
        if (!lt && !rt) return true;
        if (lt && rt)
        {
            if (lt->val != rt->val) return false;
            bool lf = _isSymmetric(lt->left, rt->right);
            if (!lf) return false;
            bool rf = _isSymmetric(lt->right, rt->left);
            if (!rf) return false;
            return true;
        }
        else  
            return false;
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

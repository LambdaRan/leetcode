
#include <iostream>
#include <algorithm>
#include <sstream>
#include <functional>
#include <utility>
#include <vector>
#include <string>
#include <stack>

//#include <stdio.h>

using namespace std;


/*
* Name: 100. Same Tree
* Website: https://leetcode.com/problems/same-tree/description/
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        stack<TreeNode*> skp;
        stack<TreeNode*> skq;
        skp.push(p);
        skq.push(q);
        while (!skp.empty() && !skq.empty())
        {
            TreeNode* curp = skp.top();
            skp.pop();
            TreeNode* curq = skq.top();
            skq.pop();

            if (!curp && !curq) continue;
            if ((!curp && curq) || (curp && !curq)) return false;
            if (curp && curq)
            {
                if (curp->val != curq->val) return false;

                skp.push(curp->left);
                skp.push(curp->right);

                skq.push(curq->left);
                skq.push(curq->right);
            }
        }

        if (skp.empty() && skq.empty())
            return true;
        else 
            return false;
    }
    bool isSameTree_v1(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if (p && q)
        {
            if (p->val != q->val) return false;
            bool left = isSameTree(p->left, q->left);
            if (!left) return false;
            bool right = isSameTree(p->right, q->right);
            if (!right) return false;

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


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
* Name: 
* Website: 
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

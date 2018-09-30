
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
* Name: 110. Balanced Binary Tree
* Website: https://leetcode.com/problems/balanced-binary-tree/description/
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
    bool isBalanced(TreeNode* root) {
        return TreeDepth(root) != -1;
    }
    int TreeDepth(TreeNode* pRoot)
    {
        if (pRoot == NULL) return 0;
        int left = TreeDepth(pRoot->left);
        if (left == -1) return -1;
        int right = TreeDepth(pRoot->right);
        if (right == -1) return -1;
        if (abs(left-right) > 1) return -1;
        return left > right ? left + 1 : right + 1;
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

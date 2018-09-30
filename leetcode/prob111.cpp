
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
* Name: 111. Minimum Depth of Binary Tree
* Website: https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
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
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int lth = minDepth(root->left);
        int rth = minDepth(root->right);
        return 1 + (min(lth, rth) ? min(lth, rth) : max(lth, rth));
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

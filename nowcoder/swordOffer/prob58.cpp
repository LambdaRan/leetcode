
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;

/*
* Name: 对称的二叉树
* Description: 请实现一个函数，用来判断一颗二叉树是不是对称的。
* 注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
*
*/
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x)
        : val(x), left(NULL), right(NULL)
    {}
};

class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        if (pRoot == NULL) return true;
        return isSame(pRoot->left, pRoot->right);
    }
private: 
    bool isSame(TreeNode* pleft, TreeNode* pright)
    {
        if (pleft == NULL) return pright == NULL;
        if (pright == NULL) return false;

        if (pleft->val != pright->val) return false;
        return isSame(pleft->left, pright->right) && isSame(pleft->right, pright->left);
    }

bool isSymmetric_v1(TreeNode* root) 
{
    if(root==NULL) return true;
    queue<TreeNode*> q1,q2;
    TreeNode *left,*right;
    q1.push(root->left);
    q2.push(root->right);
    while(!q1.empty() and !q2.empty())
    {
        left = q1.front();
        q1.pop();
        right = q2.front();
        q2.pop();
        //两边都是空
        if(NULL==left && NULL==right)
            continue;
        //只有一边是空
        if(NULL==left||NULL==right)
            return false;
        if (left->val != right->val)
            return false;
        q1.push(left->left);
        q1.push(left->right);
        q2.push(right->right);
        q2.push(right->left);
    }
        
    return true;
}
};

int main() 
{
    Solution s;

    std::cout << "method 1: \n";

    std::cout << std::endl;
    return 0;
}

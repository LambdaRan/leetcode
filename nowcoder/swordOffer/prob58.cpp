
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

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
};

int main() 
{
    Solution s;

    std::cout << "method 1: \n";

    std::cout << std::endl;
    return 0;
}

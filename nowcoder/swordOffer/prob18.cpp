
#include <iostream>
#include <algorithm>
#include <queue>


using namespace std;

/*
* Name: 二叉树的镜像
* Description: 操作给定的二叉树，将其变换为源二叉树的镜像。
* 输入描述: 二叉树的镜像定义：
* 源二叉树 
*    	    8
*    	   /  \
*    	  6   10
*    	 / \  / \
*    	5  7 9 11
*
* 镜像二叉树
*    	    8
*    	   /  \
*    	  10   6
*    	 / \  / \
*    	11 9 7  5
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) 
        : val(x), left(NULL), right(NULL) 
    {}
};

class Solution {
public:
    // void Mirror(TreeNode* pRoot)
    // {
    //     if (pRoot == NULL) return;

    //     std::queue<TreeNode*> queue;
    //     queue.push(pRoot);

    //     while (!queue.empty())
    //     {
    //         TreeNode* cur = queue.top();
    //         queue.pop();

    //         TreeNode* tmp = cur->left;
    //         cur->right = cur->left;
    //         cur->left = tmp;

    //         if (cur->left != NULL)
    //             queue.push(cur->left);
    //         if (cur->right != NULL)
    //             queue.push(cur->right);
    //     }
    // }
    void Mirror1(TreeNode *pRoot) {

        if (pRoot == NULL) return;
        if (pRoot->left == NULL && pRoot->right == NULL) return;
        //if (pRoot->left != NULL)
            Mirror1(pRoot->left);
        //if (pRoot->right != NULL)
            Mirror1(pRoot->right);

        TreeNode *tmp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = tmp;
    }
    void Mirror_v2(TreeNode *pRoot) {
        if (pRoot != NULL)
        {
            swap(pRoot->left, pRoot->right);
            Mirror_v2(pRoot->left);
            Mirror_v2(pRoot->right);
        }
    }
};

int main() 
{
    Solution s;

    std::cout << "method 1: \n";

    std::cout << std::endl;
    return 0;
}
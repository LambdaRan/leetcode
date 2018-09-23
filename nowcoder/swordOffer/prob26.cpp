
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

/*
* Name: 二叉搜索树与双向链表
* Description: 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
* 要求不能创建任何新的结点，只能调整树中结点指针的指向。
*
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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if (pRootOfTree == NULL) return NULL;

        stack<TreeNode*> treeStack;
        TreeNode head(0);
        TreeNode* pre = &head;
        TreeNode* rootCur = pRootOfTree;

        while (rootCur || !treeStack.empty())
        {
            while (rootCur)
            {
                treeStack.push(rootCur);
                rootCur = rootCur->left;
            }

            rootCur = treeStack.top();
            treeStack.pop();

            rootCur->left = pre;
            pre->right = rootCur;
            pre = rootCur;
            rootCur = rootCur->right;
        }
        
        head.right->left = NULL;
        return head.right;
    }   
public:
    // 思想：二叉搜索树的中序线索化
    TreeNode* Convert_Recursive(TreeNode* pRootOfTree)
    {
        if (pRootOfTree == NULL) return NULL;
        
        TreeNode head(0);
        TreeNode* pre = &head;
        pre->left = pRootOfTree;
        _inThreadingRecursive(&pre, pRootOfTree);
        head.right->left = NULL;
        return head.right;
    }
private:
    void _inThreadingRecursive(TreeNode** pre, TreeNode* cur)
    {
        if (cur)
        {
            // 递归左子树线索化
            _inThreadingRecursive(pre, cur->left);

            // 没有左子树，指向前驱
            //if (cur->left == NULL)
            //{
                cur->left = (*pre);
            //}

            // 前驱没有右子树，前驱结点右子树指针指向当前结点
            //if ((*pre)->right == NULL)
            //{
                (*pre)->right = cur;
            //}

            (*pre) = cur;
            // 递归右子树线索化
            _inThreadingRecursive(pre, cur->right);
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

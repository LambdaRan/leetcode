
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

/*
* Name: 二叉搜索树的第k个结点
* Description: 给定一颗二叉搜索树，请找出其中的第k小的结点。
* 例如， 5 / \ 3 7 /\ /\ 2 4 6 8 中，按结点数值大小顺序第三个结点的值为4。
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
    // 非递归中序遍历搜索二叉树得到第k个节点
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if (pRoot == NULL) return NULL;
        if (k <= 0) return NULL;
        TreeNode* cur = pRoot;
        std::stack<TreeNode*> treeStack;
        int count = 0;
        while (cur != NULL || !treeStack.empty())
        {
            while (cur != NULL)
            {
                treeStack.push(cur);
                cur = cur->left;
            }
            if (!treeStack.empty())
            {
                cur = treeStack.top();
                treeStack.pop();
                ++count;
                if (count == k)
                    return cur;
                cur = cur->right;
            }
        }
        return NULL; 
    }
    TreeNode* KthNode_Recursive(TreeNode* pRoot, int k)
    {
        int count = 0;
        return _KthNode_Recursive(pRoot, count, k);
    }
    TreeNode* _KthNode_Recursive(TreeNode* pRoot, int& count, int k)
    {
        if (pRoot != NULL)
        {
            TreeNode* node = _KthNode_Recursive(pRoot->left, count, k);
            if (node != NULL) return node;
            ++count;
            if (count == k) return pRoot;
            node == _KthNode_Recursive(pRoot->right, count, k);
            if (node != NULL) return node;
        }
        return NULL;
    }
};
int main() 
{
    Solution s;

    std::cout << "method 1: \n";

    std::cout << std::endl;
    return 0;
}

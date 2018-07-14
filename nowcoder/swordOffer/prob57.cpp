
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

/*
* Name: 二叉树的下一个结点
* Description: 给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
* 注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
*
*/
struct TreeLinkNode 
{
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) 
        : val(x), left(NULL), right(NULL), next(NULL) 
    {}
};

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if (pNode == NULL) return NULL;

        if (pNode->right) // 有有孩子，返回右孩子的最左边节点
        {
            TreeLinkNode* rightNodeSubLeft = pNode->right;
            while (rightNodeSubLeft->left)
                rightNodeSubLeft = rightNodeSubLeft->left;
            return rightNodeSubLeft;            
        }

        while (pNode->next)
        {
            TreeLinkNode* parentNode = pNode->next;
            if (parentNode->left && parentNode->left == pNode)
                return parentNode;
            else  // 右孩子 一直找到最上边父节点的左孩子是当前节点（左支树都遍历完了）
                pNode = pNode->next;;            
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

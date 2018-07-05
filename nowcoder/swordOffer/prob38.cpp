
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

/*
* Name: 二叉树的深度
* Description: 输入一棵二叉树，求该树的深度。
* 从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
*
*/
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) 
    {}
};
class Solution {
public:
    int TreeDepth_Loop(TreeNode* pRoot)
    {
        if (pRoot == NULL) return 0;

        std::queue<TreeNode*> treeQueue;
        treeQueue.push(pRoot);
        size_t count = 0;
        size_t levelCount = 1;
        int depth = 0;

        while (!treeQueue.empty())
        {
            TreeNode* top = treeQueue.front();
            treeQueue.pop();
            ++count;
            if (top->left)
                treeQueue.push(top->left);
            if (top->right)
                treeQueue.push(top->right);
            if (count == levelCount)
            {
                count = 0;
                levelCount = treeQueue.size();
                ++depth;
            }
        }

        return depth;
    }
    int TreeDepth_Recursive(TreeNode* pRoot)
    {
        return _treeDepthRecursive(pRoot);
    }
private: 
    int _treeDepthRecursive(TreeNode* pRoot)
    {
        if (pRoot == NULL) return 0;

        int left = _treeDepthRecursive(pRoot->left);
        int right = _treeDepthRecursive(pRoot->right);

        return left > right ? left + 1 : right + 1;
    }
};

int main() 
{
    Solution s;

    std::cout << "method 1: \n";

    std::cout << std::endl;
    return 0;
}

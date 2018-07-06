
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

/*
* Name: 平衡二叉树
* Description: 输入一棵二叉树，判断该二叉树是否是平衡二叉树。
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
    bool IsBalanced_Solution(TreeNode* pRoot) {

        std::pair<int, bool> result = _heightAndIsBalanced(pRoot);
        return result.second;
    }
private: 
    std::pair<int, bool> _heightAndIsBalanced(TreeNode* node)
    {
        if (node == NULL) return std::make_pair(0, true);

        std::pair<int, bool> leftHeight = _heightAndIsBalanced(node->left);
        if (!leftHeight.second) 
            return leftHeight;
        std::pair<int, bool> rightHeight = _heightAndIsBalanced(node->right);
        if (!rightHeight.second)
            return rightHeight;
        int maxDepth = 0;
        int diff = 0;
        if (leftHeight.first < rightHeight.first)
        {
            maxDepth = rightHeight.first;
            diff = rightHeight.first - leftHeight.first;
        }
        else  
        {
            maxDepth = leftHeight.first;
            diff = leftHeight.first - rightHeight.first;
        }
        if (diff > 1) return std::make_pair(0, false);

        return std::make_pair(maxDepth+1, true);
    }
};
int main() 
{
    Solution s;

    std::cout << "method 1: \n";

    std::cout << std::endl;
    return 0;
}

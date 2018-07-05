
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

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

    }
};
int main() 
{
    Solution s;

    std::cout << "method 1: \n";

    std::cout << std::endl;
    return 0;
}

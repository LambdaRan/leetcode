
#include <iostream>
#include <queue>


using namespace std;

/*
* Name: 从上往下打印二叉树
* Description: 从上往下打印出二叉树的每个节点，同层节点从左至右打印。
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
    // 层序遍历 广度优先遍历
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        if (root == NULL) return vector<int>();
        queue<TreeNode*> treeNodeQueue;
        vector<int> resultVec;
        treeNodeQueue.push(root);
        while (!treeNodeQueue.empty())
        {
            TreeNode* preNode = treeNodeQueue.front();
            treeNodeQueue.pop();
            resultVec.push_back(preNode->val);
            if (preNode->left)
                treeNodeQueue.push(preNode->left);
            if (preNode->right)
                treeNodeQueue.push(preNode->right);
        }
        return resultVec;
    }
};
int main() 
{
    Solution s;

    std::cout << "method 1: \n";

    std::cout << std::endl;
    return 0;
}
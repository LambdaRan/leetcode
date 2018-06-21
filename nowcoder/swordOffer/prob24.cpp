

#include <iostream>
#include <vector>


using namespace std;

/*
* Name: 二叉树中和为某一值的路径
* Description: 输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
* 路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
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
    vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
        if (root == NULL) return;

        vector<vector<int>> result;
        vector<TreeNode*> deepVector;
        TreeNode* cur = root;
        TreeNode *preTurn = NULL; // 指向前一个被访问的节点 
        int sum = 0;

        while (cur != NULL || !deepVector.empty())
        {
            while (cur != NULL)
            {
                deepVector.push_back(cur);
                sum += cur->val;
                if (sum == expectNumber)
                {
                    vector<int> onePath;
                    for (TreeNode* v : deepVector)
                        onePath.push_back(v->val);
                    result.push_back(onePath);
                }
                cur = cur->left;
            }

            cur = deepVector.back();

            // 当前节点的右孩子如果为空或者已经被访问，则访问当前节点
            if (cur->right == NULL || cur->right == preVisit) // 到达叶结点
            {
                sum -= cur->val;
                deepVector.pop_back();
                cur = NULL;
            }
            else  
            {
                preVisit = cur;
                cur = cur->right;
            }
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

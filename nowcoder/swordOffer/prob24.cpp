

#include <iostream>
#include <vector>
#include <stack>

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
    vector<vector<int> > FindPath(TreeNode* root, int expectNumber)
    {}
private: 
    
public:
    // 非递归
    vector<vector<int> > FindPath_loop(TreeNode* root, int expectNumber) {
        if (root == NULL) return vector<vector<int>>();

        vector<vector<int>> result;
        vector<TreeNode*> deepVector;
        TreeNode* cur = root;
        stack<TreeNode*> rightStack; 
        int sum = 0;

        while (cur != NULL || !deepVector.empty())
        {
            while (cur != NULL)
            {
                deepVector.push_back(cur);
                sum += cur->val;
                cur = cur->left;
            }

            cur = deepVector.back();

            if (cur->left == NULL && cur->right == NULL)
            {
                if (sum == expectNumber)
                {
                    vector<int> onePath;
                    for (TreeNode* v : deepVector)
                        onePath.push_back(v->val);
                    result.push_back(onePath);
                } 

                while (!deepVector.empty() && cur->right == NULL)
                {
                    deepVector.pop_back();
                    sum -= cur->val;
                    cur = deepVector.back();
                }              
                cur = NULL;                 
            } 
            else if (!rightStack.empty() && cur == rightStack.top())
            {
                while (!rightStack.empty() && cur == rightStack.top() && !deepVector.empty())
                {
                    rightStack.pop();
                    deepVector.pop_back();
                    sum -= cur->val;
                    cur = deepVector.back();
                }
                cur = NULL;
            }
            else  
            {
                rightStack.push(cur);
                cur = cur->right;                
            }
        }

        return result;
    }
};

int main() 
{
    Solution s;

    std::cout << "method 1: \n";

    std::cout << std::endl;
    return 0;
}

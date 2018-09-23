

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
    {
        if (root == NULL) return vector<vector<int>>();

        vector<vector<int>> result;
        vector<int> path;
        int currentSum = 0;
        _findPath(root, expectNumber, path, currentSum, result);
        return result;
    }
private: 
    void _findPath(TreeNode* root, int expectNumber, 
                    vector<int>& path, int currentSum, 
                    vector<vector<int>>& result)
    {
        currentSum += root->val;
        path.push_back(root->val);

        bool isLeaf = (root->left == NULL && root->right == NULL);
        if (currentSum == expectNumber && isLeaf)
        {
            result.push_back(path);
        }

        if (root->left != NULL)
            _findPath(root->left, expectNumber, path, currentSum, result);
        if (root->right != NULL)
            _findPath(root->right, expectNumber, path, currentSum, result);

        path.pop_back();
    }
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
    vector<vector<int> > FindPath_v2(TreeNode* root,int expectNumber) 
    {
        vector<vector<int>> result;
        if (root == NULL) return result;
        int sum = 0;
        stack<TreeNode*> sk;
        vector<int> values;
        TreeNode* cur = root;
        TreeNode* preVist = NULL;
        while (cur != NULL || !sk.empty())
        {
            while (cur != NULL)
            {
                sk.push(cur);
                values.emplace_back(cur->val);
                sum += cur->val;
                cur = cur->left;
            }
            if (!sk.empty())
            {
                cur = sk.top();
                if (cur->left == NULL && cur->right == NULL && sum == expectNumber)
                    result.emplace_back(values);
                if (cur->right != NULL && cur->right != preVist)
                {
                    cur = cur->right; //转向未遍历过的右子树
                }
                else
                {
                    preVist = cur; //保存上一个已遍历的节点
                    sk.pop();
                    values.pop_back(); //从当前路径删除
                    sum -= cur->val;
                    cur = NULL;
                }  
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

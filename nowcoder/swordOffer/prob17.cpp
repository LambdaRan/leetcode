
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

/*
* Name: 树的子结构
* Description: 输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        bool result = false;

        if (pRoot1 != NULL && pRoot2 != NULL)
        {
            if (pRoot1->val == pRoot2->val)
                result = doesTree1HaveTree2(pRoot1, pRoot2);
            if (!result)
                result = HasSubtree(pRoot1->left, pRoot2);
            if (!result)
                result = HasSubtree(pRoot1->right, pRoot2);
        }
        return result;
    }
    bool HasSubtree1(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (pRoot1 == NULL || pRoot2 == NULL) return false;
        vector<int> valVecRoot1 = _preOrderLoop(pRoot1);
        vector<int> valVecRoot2 = _preOrderLoop(pRoot2);

        vector<int>::iterator first1 = valVecRoot1.begin();

        while (true)
        {
            bool isContinue = false;
            first1 = find(first1, valVecRoot1.end(), valVecRoot2[0]);
            if (first1 == valVecRoot1.end())
                return false;
            
            vector<int>::iterator first2 = valVecRoot2.begin();
            vector<int>::iterator last2 = valVecRoot2.end();
            for ( ; first1 != valVecRoot1.end(); ++first1, ++first2)
            {
                if (first2 == last2) return true;
                if (*first1 != *first2)
                {
                    isContinue = true;
                    break;
                }
            }
            if (!isContinue)
            {
                if (first2 != last2)
                    return false;
                else
                    return true;               
            }
        }
    }
private: 
    bool doesTree1HaveTree2(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (pRoot2 == NULL) return true;
        if (pRoot1 == NULL) return false;

        if (pRoot1->val != pRoot2->val) return false;
        
        return doesTree1HaveTree2(pRoot1->left, pRoot2->left) && 
                doesTree1HaveTree2(pRoot1->right, pRoot2->right);
    }
    vector<int> _preOrderLoop(TreeNode* root)
    {
        vector<int> valVector;
        std::stack<TreeNode *> treeStack;
        treeStack.push(root);
        while (!treeStack.empty())
        {
            TreeNode *tmp = treeStack.top();
            treeStack.pop();
            valVector.push_back(tmp->val);
            if (tmp->right != NULL)
                treeStack.push(tmp->right);
            if (tmp->left != NULL)
                treeStack.push(tmp->left); 
        }
        return valVector;  
    }
};

int main() 
{
    Solution s;

    std::cout << "method 1: \n";

    std::cout << std::endl;
    return 0;
}
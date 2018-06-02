

#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <stack>


using namespace std;



/*
* Name: 重建二叉树
* Description: 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
* 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}
* 和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
*
*/

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) 
        : val(x), left(NULL), right(NULL) 
    {}
};

void printDubug(const vector<int>& vec)
{
    if (vec.empty())
    {
        cout << "empty" << endl;
    }
    else  
    {
        for (auto &v : vec)
            cout << v << " ";
        cout << endl;
    }
}
class Solution {
public:
    // 运行时间：7ms
    // 占用内存：476k
    TreeNode* reConstructBinaryTree(vector<int> preV,vector<int> inV) 
    {
        if (preV.empty()) return NULL;

        TreeNode* node = new TreeNode(preV[0]);
        
        vector<int>::iterator ret = find(inV.begin(), inV.end(), preV[0]);
        vector<int> inLeftSub(inV.begin(), ret);
        vector<int> inRightSub(ret+1, inV.end());

        vector<int> preLeftSub(preV.begin()+1, preV.begin()+1+inLeftSub.size());
        vector<int> preRightSub(preV.begin()+1+inLeftSub.size(), preV.end());

        node->left = reConstructBinaryTree(preLeftSub, inLeftSub);
        node->right = reConstructBinaryTree(preRightSub, inRightSub);

        return node;
    }
};
void _free(TreeNode *t)
{
    assert(t != NULL);
    delete t;
    t = NULL;
}
void _lastRecursiveClear(TreeNode *h)
{
	if (h == NULL) return;
	_lastRecursiveClear(h->left);
	_lastRecursiveClear(h->right);
	_free(h);     
}
// 中序遍历
void _visit(TreeNode *t)
{
    assert(t != NULL);
    //printf("%c", t->data_);
    std::cout << t->val << " ";
}
void midOrderLoop(TreeNode* head)
{
    std::stack<TreeNode *> stk;
    TreeNode *cur = head;
    while (cur != NULL || !stk.empty())
    {
        while (cur != NULL)
        {
            stk.push(cur);
            cur = cur->left;
        }
        if (!stk.empty())
        {
            cur = stk.top();
            stk.pop();
            _visit(cur);
            cur = cur->right;
        }
    }    
}
int main() 
{
    vector<int> pVector = {1,2,4,7,3,5,6,8};
    vector<int> iVector = {4,7,2,1,5,3,8,6};
    Solution s;

    std::cout << "method 1: \n";
    
    TreeNode * ret = s.reConstructBinaryTree(pVector, iVector);
    
    // 中序遍历
    cout << "中序遍历:\n";
    midOrderLoop(ret);
    std::cout << std::endl;

    _lastRecursiveClear(ret);

    return 0;
}

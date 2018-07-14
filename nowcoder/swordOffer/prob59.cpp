
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

/*
* Name: 按之字形顺序打印二叉树
* Description: 请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，
* 第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。
*
*/
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x)
        : val(x), left(NULL), right(NULL)
    {}
};

class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        if (pRoot == NULL) return vector<vector<int>>();

        vector<vector<int>> result;
        // 使用双端队列
        std::deque<TreeNode*> treeLevelDeque;
        treeLevelDeque.push_back(pRoot);
        bool isReverse = false;
        size_t count = 0;
        size_t levelCount = 1;
        TreeNode* top = NULL;
        vector<int> levelVector;
        while (!treeLevelDeque.empty())
        {
            ++count;
            if (isReverse) // 从右到左
            {
                top = treeLevelDeque.back();
                treeLevelDeque.pop_back();
                if (top->right)
                    treeLevelDeque.push_front(top->right); 
                if (top->left)
                    treeLevelDeque.push_front(top->left);                               
            }
            else  // 从左到右
            {
                top = treeLevelDeque.front();
                treeLevelDeque.pop_front();
                if (top->left)
                    treeLevelDeque.push_back(top->left);
                if (top->right)
                    treeLevelDeque.push_back(top->right); 
            }
            levelVector.push_back(top->val);
            if (count == levelCount)
            {
                count = 0;
                levelCount = treeLevelDeque.size();
                isReverse = !isReverse;
                result.push_back(levelVector);
                levelVector.clear();
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

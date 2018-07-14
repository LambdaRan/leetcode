
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

/*
* Name: 把二叉树打印成多行
* Description: 从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
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
        
        if (pRoot == NULL) return std::vector<std::vector<int>>();
        std::vector<std::vector<int>> result;
        std::queue<TreeNode*> treeQueue;
        treeQueue.push(pRoot);
        size_t count = 0;
        size_t levelCount = 1;
        std::vector<int> levelVector;
        while (!treeQueue.empty())
        {
            ++count;
            TreeNode* top = treeQueue.front();
            treeQueue.pop();
            if (top->left)
                treeQueue.push(top->left);
            if (top->right)
                treeQueue.push(top->right);
            levelVector.push_back(top->val);
            if (count == levelCount)
            {
                count = 0;
                levelCount = treeQueue.size();
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

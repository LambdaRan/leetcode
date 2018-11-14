
#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <utility>
#include <iterator>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;
/*
* Name: 404. Sum of Left Leaves
* Website: https://leetcode.com/problems/sum-of-left-leaves/description/
* Description: 
*
*/
class Solution
{
  public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    int sumOfLeftLeaves(TreeNode* root){
        if (!root) return 0; 
        stack<TreeNode*> stk;
        stk.push(root);
        int sum = 0;
        while (!stk.empty())
        {
            TreeNode* cur = stk.top();
            stk.pop();
            if (cur->left != NULL)
            {
                if (cur->left->left == NULL && cur->left->right == NULL)
                    sum += cur->left->val;
                else 
                    stk.push(cur->left);
            }
            if (cur->right != NULL)
                stk.push(cur->right);
        }
        return sum;
    }
    int sumOfLeftLeaves_v1(TreeNode* root) {
        if (!root) return 0;
        stack<pair<TreeNode*, bool>> stk;
        stk.push(make_pair(root, false));
        int sum = 0;
        while (!stk.empty())
        {
            auto cur = stk.top();
            stk.pop();
            if (cur.second && cur.first->left == NULL && cur.first->right == NULL)
                sum += cur.first->val;
            if (cur.first->left)
                stk.push(make_pair(cur.first->left, true));
            if (cur.first->right)
                stk.push(make_pair(cur.first->right, false));
        }
        return sum;
    }
};

int main()
{
    Solution s;

    std::cout << "method 1: \n";
    //std::cout <<  "function(): true <------> " << boolToString(s.function()) << "\n";

    std::cout << std::endl;
    return 0;
}
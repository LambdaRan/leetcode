
#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <utility>
#include <iterator>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
/*
* Name: 437. Path Sum III
* Website: https://leetcode.com/problems/path-sum-iii/description/
* Description: 
*
*/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
  public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        unordered_map<int, int> preSumMap = {{0, 1}};
        return helper(root, 0, sum, preSumMap);
    }
    int helper(TreeNode* root, int curSum, int target, unordered_map<int, int>& preSum)
    {
        if (root == nullptr) return 0;
        curSum += root->val;
        int result = (preSum.find(curSum-target) == preSum.end()) ? 0 : preSum[curSum-target];
        preSum[curSum] += 1;
        result += helper(root->left, curSum, target, preSum) 
                + helper(root->right, curSum, target, preSum);
        preSum[curSum] -= 1;
        return result;
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
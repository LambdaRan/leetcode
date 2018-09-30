
#include <iostream>
#include <algorithm>
#include <sstream>
#include <functional>
#include <utility>
#include <vector>
#include <string>
#include <stack>
#include <queue>

//#include <stdio.h>

using namespace std;


/*
* Name: 108.Convert Sorted Array to Binary Search Tree
* Website: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
* Description: 
*
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
private:
    TreeNode* helper(vector<int>& nums, int start, int end) {
        TreeNode* root = nullptr;
        if (start <= end) {
            int mid = end - (end-start)/2;
            root = new TreeNode(nums[mid]);
            root->left = helper(nums, start, mid-1);
            root->right = helper(nums, mid+1, end);
        }
        return root;
    }
public: 
    TreeNode* sortedArrayToBST_v1(vector<int>& nums) {

        TreeNode* head = nullptr;
        switch (nums.size())
        {
            case 0:
                break;
            case 1:
                head = new TreeNode(nums[0]);
                break;
            case 2:
                head = new TreeNode(nums[1]);
                head->left = new TreeNode(nums[0]);
                break;
            default: 
            {
                int mid = static_cast<int>(nums.size()/2);
                // if (nums.size() % 2 != 0)
                //     mid = static_cast<int>(nums.size()/2) + 1;
                // else  
                //     mid = static_cast<int>(nums.size()/2);
                vector<int> ltv(nums.begin(), next(nums.begin(), mid));
                vector<int> rtv(next(nums.begin(), mid+1), nums.end());
                head = new TreeNode(nums[mid]);
                head->left = sortedArrayToBST_v1(ltv);
                head->right = sortedArrayToBST_v1(rtv);
                break;
            }
        }
        return head;
    }
};

int main() 
{
    string line;
    while (getline(cin, line)) {
        // ListNode* head = stringToListNode(line);
        // getline(cin, line);
        // int n = stringToInteger(line);
        
        // //ListNode* ret = Solution().removeNthFromEnd(head, n);

        // string out = listNodeToString(ret);
        //cout << out << endl;
    }
    return 0;
}

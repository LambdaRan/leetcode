
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

/*
* Name: 序列化二叉树
* Description: 请实现两个函数，分别用来序列化和反序列化二叉树
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
    char* Serialize(TreeNode *root) {    
        
    }
    
    TreeNode* Deserialize(char *str) {
    
    }
};

int main() 
{
    Solution s;

    std::cout << "method 1: \n";

    std::cout << std::endl;
    return 0;
}

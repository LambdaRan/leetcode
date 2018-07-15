
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>

#include <string.h>

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

class Solution
{
  public:
    string sHelper(TreeNode* node)
    {
        if (node == NULL)
            return "#";
        return std::to_string(node->val) + "," +
               sHelper(node->left) + "," +
               sHelper(node->right);
    }
    char* Serialize(TreeNode* root)
    {
        string s = sHelper(root);
        char *ret = new char[s.length() + 1];
        strcpy(ret, const_cast<char *>(s.c_str()));
        return ret;
    }
    TreeNode* dHelper(stringstream &ss)
    {
        string str;
        std::getline(ss, str, ',');
        if (str == "#")
            return NULL;
        else
        {
            TreeNode *node = new TreeNode(stoi(str));
            node->left = dHelper(ss);
            node->right = dHelper(ss);
            return node;
        }
    }
    TreeNode* Deserialize(char* str)
    {
        stringstream ss(str);
        delete[] str;
        str = NULL;
        return dHelper(ss);
    }
};


int main() 
{
    Solution s;

    std::cout << "method 1: \n";

    std::cout << std::endl;
    return 0;
}

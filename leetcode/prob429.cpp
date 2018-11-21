
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
* Name: 429. N-ary Tree Level Order Traversal
* Website: https://leetcode.com/problems/n-ary-tree-level-order-traversal/description/
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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if (!root) return result;
        size_t count = 0;
        size_t levelCount = 1;
        std::queue<Node*> levelQueue;
        levelQueue.push(root);
        vector<int> levelVector;
        while (!levelQueue.empty())
        {
            ++count;
            Node* cur = levelQueue.front();
            levelQueue.pop();
            levelVector.emplace_back(cur->val);
            for (auto& v : cur->children)
                levelQueue.push(v);
            if (count == levelCount)
            {
                count = 0;
                levelCount = levelQueue.size();
                result.emplace_back(levelVector);
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
    //std::cout <<  "function(): true <------> " << boolToString(s.function()) << "\n";

    std::cout << std::endl;
    return 0;
}
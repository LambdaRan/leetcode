
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
* Name: 427. Construct Quad Tree
* Website: https://leetcode.com/problems/construct-quad-tree/description/
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
    // 坐标 左闭右开
    Node* _recursive(vector<vector<int>>& grid, 
                     int xTopLeft, 
                     int yTopLeft, 
                     int length)
    {
        if (length == 1)
            return new Node(grid[xTopLeft][yTopLeft]==1, true, nullptr, nullptr, nullptr, nullptr);

        int newLength = length / 2;
        // 左上角
        Node* mTopLeft = _recursive(grid, xTopLeft, yTopLeft, newLength);
        // 右上角
       Node* mTopRight = _recursive(grid, xTopLeft, yTopLeft+newLength, newLength);
        // 左下角
        Node* mBottomLeft = _recursive(grid, xTopLeft+newLength,yTopLeft, newLength);
        // 右下角
        Node* mBottomRight = _recursive(grid, xTopLeft+newLength, yTopLeft+newLength, newLength);
        if ((mTopLeft->isLeaf && mTopRight->isLeaf && mBottomLeft->isLeaf && mBottomRight->isLeaf) &&
           ((mTopLeft->val && mTopRight->val && mBottomLeft->val && mBottomRight->val) || 
           !(mTopLeft->val || mTopRight->val || mBottomLeft->val || mBottomRight->val)))
        { // 合并成一个大节点
            bool val = mTopLeft->val;
            delete mTopLeft;        mTopLeft = nullptr;
            delete mTopRight;       mTopRight = nullptr;
            delete mBottomLeft;     mBottomLeft = nullptr;
            delete mBottomRight;    mBottomRight = nullptr;
            return new Node(val, true, nullptr, nullptr, nullptr, nullptr);
        }
        
        return new Node(true, false, mTopLeft, mTopRight, mBottomLeft, mBottomRight);
    }
    Node* construct(vector<vector<int>>& grid) {
        if (grid.empty()) return nullptr;
        return _recursive(grid, 0, 0, grid.size());
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
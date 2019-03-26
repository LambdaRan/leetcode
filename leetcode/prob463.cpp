
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <utility>

#include <cctype>

using namespace std;
/*
* Name: 463. Island Perimeter
* WebSite: https://leetcode.com/problems/island-perimeter/
* Description: 
*
*/
class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    int islandPerimeter(vector<vector<int>>& grid) {
        size_t rows = grid.size();
        size_t cols = grid[0].size();
        int island = 0;
        int nei = 0;
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    ++island;
                    if (i < rows-1)
                        nei += grid[i+1][j];
                    if (j < cols-1)
                        nei += grid[i][j+1];
                }
            }
        }
        return island * 4 - nei * 2;
    }
};
int main() 
{
    Solution s;

    std::cout << "method 1: \n";

    std::cout << std::endl;
    return 0;
}
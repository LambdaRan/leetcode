#include <iostream>
#include <string>
#include <vector>

/*
* Name: 11. Container With Most Water
* Description: 
* Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
* n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, 
* which together with x-axis forms a container, such that the container contains the most water.
*
* Note: You may not slant the container and n is at least 2.
*/
class Solution {
public:
    /*
    * Runtime: 19 ms
    * Your runtime beats 29.18 % of cpp submissions. 
    */
    int maxArea(std::vector<int>& height) {
        
        int _left = 0;
        int _right = height.size() - 1;
        int _maxarea = 0;
        int _max = 0;
        while (_left < _right) {
            
            if (height[_left] < height[_right]) {
                _max = (_right - _left) * height[_left];
                ++_left;   
            } else {
                _max = (_right - _left) * height[_right];
                --_right;           
            }
            _maxarea = _max > _maxarea ? _max : _maxarea;
        }
        
        return _maxarea;
    }
};
std::string boolToString(bool input) {
    return input ? "True" : "False";
}
int main() 
{
    Solution s;

    std::cout << "method 1: \n";
    std::cout <<  "function(): true <------> " << boolToString(true) << "\n";

    std::cout << std::endl;
    return 0;
}
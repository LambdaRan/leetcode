
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
/*
* Name: 46. Permutations
* Description: Given a collection of distinct integers, return all possible permutations.
* 
* Example:
* 
* Input: [1,2,3]
* Output:
* [
*   [1,2,3],
*   [1,3,2],
*   [2,1,3],
*   [2,3,1],
*   [3,1,2],
*   [3,2,1]
* ]
* 
*/
class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> result;
        if (nums.empty()) return result;

        size_t vectorSize = nums.size();
        if (vectorSize == 1) 
        {
            result.push_back(nums);
            return result;
        } 
        std::sort(nums.begin(), nums.end());
        result.push_back(nums);
        bool loop = true;
        while (loop)
        {
            size_t head = vectorSize - 1;
            while (true)
            {
                size_t tailOne = head;
                // 找到左边字符小于右边字符位置
                // 如：1，4，5，3，2 
                // head：4  tailOne:5
                if (nums[--head] < nums[tailOne]) 
                {
                    size_t tailTwo = vectorSize;
                    // 从右到左找到第一个大于head所指字符的位置
                    // 如：1，4，5，3，2
                    // head:4   tailTwo:5
                    while (!(nums[head] < nums[--tailTwo]));

                    std::swap(nums[head], nums[tailTwo]);
                    std::reverse(nums.begin()+tailOne, nums.end());
                    
                    result.push_back(nums);
                    break;
                }

                if (head == 0)
                {
                    std::reverse(nums.begin(), nums.end());
                    loop = false;
                    break;
                }
            }
        }
        return result;    
    }
    vector<vector<int>> permute_v1(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.empty()) return result;

        _helper(nums, 0, result);
        return result;        
    }
private: 
    void _helper(vector<int>& nums, 
                int index, 
                vector<vector<int>>& result)
    {
        if (index == nums.size())
        {
            result.push_back(nums);
        }
        else  
        {
            for (int i = index; i < nums.size(); ++i)
            {
                if (i != index)
                    std::swap(nums[i], nums[index]);
                _helper(nums, index+1, result);
                if (i != index)
                    std::swap(nums[i], nums[index]);                
            }
        }
    }
};
void printResult(const vector<vector<int>>& vec)
{
    std::cout << "[ \n";
    for (int i = 0; i < vec.size(); ++i)
    {
        std::cout << "[";
        for (int j = 0; j < vec[i].size(); ++j)
        {
            std::cout << vec[i][j] << " ";
        }
        std::cout << "]\n";
    }
    std::cout << "]" << std::endl;
}
int main() 
{
    Solution s;
    vector<vector<int>> res;
    vector<int> vec1 = {1,2,3};
    std::cout << "method 1: \n";
    res = s.permute(vec1);
    printResult(res);
    std::cout << std::endl;
    return 0;
}
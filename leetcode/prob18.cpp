
#include <iostream>
#include <vector>

#include <string>

using namespace std;

/*
* Name: 18. 4Sum
* Description: Given an array nums of n integers and an integer target, 
*   are there elements a, b, c, and d in nums such that a + b + c + d = target? 
*   Find all unique quadruplets in the array which gives the sum of target.
*
* Note:
* The solution set must not contain duplicate quadruplets.
* 
* Example:
* Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
* A solution set is:
* [
*   [-1,  0, 0, 1],
*   [-2, -1, 1, 2],
*   [-2,  0, 0, 2]
* ]
*
*/
class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<int> tmp(4);

    }
    void findQuadruplets(vector<vector<int>>& result, vector<int>& preVector, int preSum, vector<int>& input, int index, int target)
    {
        if (index < input.size())
        {
            if (preVector.size() < 3)
            {
                preSum += input[index];
                preVector.push_back(input[index++]);
                findQuadruplets(result, preVector, preSum, input, index, target);
            }
            else  
            {
                for (int i = index; i < input.size(); ++i)
                {
                    if (target == preSum + input[i])
                    {
                        preVector.push_back(input[i]);
                        result.push_back(preVector);
                        preVector.pop_back();
                        break;
                    }
                }
                preVector.pop_back();
            }
        }
    }   
};

std::string boolToString(bool input) {
    return input ? "True" : "False";
}
int main() 
{
    Solution s;

    std::cout << "method 1: \n";
    std::cout <<  "function(): true <------> " << boolToString(s.function()) << "\n";

    std::cout << std::endl;
    return 0;
}
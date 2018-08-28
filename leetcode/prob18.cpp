
#include <iostream>
#include <vector>
#include <algorithm>

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
    * Runtime:  28 ms
    * Your runtime beats  38.22% of cpp submissions. 
    */
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> result;
        if (nums.size() < 4) return result;
        std::sort(nums.begin(), nums.end());
        for(size_t i = 0; i < nums.size() - 3; ++i) 
        {
            if (i>0 && nums[i-1] == nums[i]) continue;
            vector<int> n(nums.begin()+i+1, nums.end());
            vector<vector<int> > ret = threeSum(n, target-nums[i]);
            for(size_t j = 0; j < ret.size(); ++j)
            {
                ret[j].insert(ret[j].begin(), nums[i]);
                result.push_back(ret[j]);
            }
        }

        return result; 
    }
    vector<vector<int>> threeSum(vector<int>& nums, int tar) 
    {
        size_t vsize = nums.size();
        if (vsize < 3) return vector<vector<int>>();

        //std::sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        for (size_t i = 0; i < vsize; ++i) {
            int target = tar - nums[i];
            size_t left = i+1;
            size_t right = vsize -1;
            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum < target) {
                    // 去掉下面的while 111ms
                    // while (left < right && nums[left] == nums[left+1]) {
                    //     ++left;
                    // }
                    ++left;
                } else if (sum > target) {
                    // 去掉下面的while 111ms
                    // while (left < right && nums[right] == nums[right-1]) {
                    //     --right;
                    // }
                    --right;                
                } else {             
                    ret.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left+1]) ++left;
                    while (left < right && nums[right] == nums[right-1]) --right;
                    ++left;
                    --right;        
                }            
            }
            while (i + 1 < vsize && nums[i] == nums[i+1]) {
                ++i;
            }
        }
        return ret;
    }
    // void findQuadruplets(vector<vector<int>>& result, 
    //                     vector<int>& preVector, 
    //                     int preSum, 
    //                     vector<int>& input, 
    //                     int index, 
    //                     int target)
    // {
    //     if (index < input.size())
    //     {
    //         if (preVector.size() < 3)
    //         {
    //             preSum += input[index];
    //             preVector.push_back(input[index++]);
    //             findQuadruplets(result, preVector, preSum, input, index, target);
    //         }
    //         else  
    //         {
    //             for (int i = index; i < input.size(); ++i)
    //             {
    //                 if (target == preSum + input[i])
    //                 {
    //                     preVector.push_back(input[i]);
    //                     result.push_back(preVector);
    //                     preVector.pop_back();
    //                     break;
    //                 }
    //             }
    //             preVector.pop_back();
    //         }
    //     }
    // }   
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
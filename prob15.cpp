
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using std::string;
using std::vector;

/*
* Name: 15. 3Sum
* Description: 
* Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
* Find all unique triplets in the array which gives the sum of zero.
*
* Note: The solution set must not contain duplicate triplets.
* For example, given array S = [-1, 0, 1, 2, -1, -4],
* A solution set is:
* [
*   [-1, 0, 1],
*   [-1, -1, 2]
* ]
*
*/
class Solution {
public:
    /*
    * Runtime:   285 ms
    * Your runtime beats  10.67% of cpp submissions. 
    */
    vector<vector<int>> threeSum(vector<int>& nums);
    /*
    * Runtime:   124 ms
    * Your runtime beats  40.03% of cpp submissions. 
    */
    vector<vector<int>> threeSum1(vector<int>& nums);
};
void result_print(vector<vector<int>>& ret);

vector<vector<int>> Solution::threeSum(vector<int>& nums) 
{
    size_t vsize = nums.size();
    if (vsize < 3) return vector<vector<int>>();

    std::sort(nums.begin(), nums.end());
    vector<vector<int>> ret;
    for (size_t i = 0; i < vsize; ++i) {
        for (size_t j = i + 1; j < vsize; ++j) {
            int sum = -(nums[i] + nums[j]);
            if (std::binary_search(nums.begin()+j+1, nums.end(), sum)) {
                ret.push_back(vector<int>{nums[i], nums[j], sum});
            }
            while (j+1 < vsize && nums[j] == nums[j+1]) {
                ++j;
            }
        }
        while (i+1 < vsize && nums[i] == nums[i+1]) {
            ++i;
        }
    }
    return ret;
}
vector<vector<int>> Solution::threeSum1(vector<int>& nums) 
{
    size_t vsize = nums.size();
    if (vsize < 3) return vector<vector<int>>();

    std::sort(nums.begin(), nums.end());
    vector<vector<int>> ret;
    for (size_t i = 0; i < vsize; ++i) {
        int target = -nums[i];
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
void result_print(vector<vector<int>>& ret)
{
    std::cout << "[";
    for (const auto &v1 : ret) {
        std::cout << "[";
        for (const auto &v2 : v1) {
            std::cout << v2 << ",";
        }
        std::cout << "],";
    }
    std::cout << "]" << std::endl;
}
int main() 
{
    Solution s;
    std::vector<vector<int> > ret;
    std::vector<int> input1 = {-1,0,1,2,-1,-4};
    std::vector<int> input2 = {-1,0,1,2,-1,-4,0,3};
    std::vector<int> input3 = {1,1,1};
    std::string expect2 = "[[-4,1,3],[-1,-1,2],[-1,0,1]]";
    std::cout << "method 1: \n";
    // std::cout <<  "vector<vector<int>> threeSum(vector<int>& nums): \n";
    // std::cout << "expect: \n" << expect2 << '\n';
    // std::cout << "result: \n";
    // ret = s.threeSum(input2);
    // result_print(ret);
    // std::cout << std::endl;
    std::cout << "result1: \n";
    ret = s.threeSum1(input3);
    result_print(ret);
    std::cout << std::endl;
    return 0;
}
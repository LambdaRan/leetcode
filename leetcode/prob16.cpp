
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using std::vector;

/*
* Name: 16. 3Sum Closest
* Description: 
* Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
* Return the sum of the three integers. You may assume that each input would have exactly one solution.
*    For example, given array S = {-1 2 1 -4}, and target = 1.
*    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/
class Solution {
public:
    /*
    * Runtime:  10  ms
    * Your runtime beats  37.89% of cpp submissions. 
    */
    int threeSumClosest(vector<int>& nums, int target);
};
int Solution::threeSumClosest(vector<int>& nums, int target) 
{
    size_t vsize = nums.size();
    int distance = INT_MAX;
    int result = 0;
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < vsize-2; ++i) {
        // skip the duplication
        if (i>0 && nums[i] == nums[i-1]) continue;
        int a = nums[i];
        size_t low = i + 1;
        size_t high = vsize - 1;
        //convert the 3sum to 2sum problem
        while (low <= high) {
            int b = nums[low];
            int c = nums[high];
            int sum = a + b + c;
            if (sum - target == 0) {
                //got the final soultion
                return target;
            } else {
                //tracking the minmal distance
                if (std::abs(sum-target) < distance) {
                    distance = std::abs(sum - target);
                    result = sum;
                    // std::cout << "result " << result << std::endl;
                }

                if (sum - target > 0) {
                    //skip the duplication
                    while(high>1 && nums[high]==nums[high-1]) high--;
                    //move the `high` pointer
                    high--;
                } else {
                    //skip the duplication
                    while(low<vsize && nums[low]==nums[low+1]) low++;
                    //move the `low` pointer
                    low++;
                }
            }
        }
    }
    return result;
}
int main() 
{
    Solution s;
    std::vector<int> example1{-1, 2, 1, -4};
    std::vector<int> example2{1, 1, 1, 1};
    std::cout << "method 1: \n";
    //std::cout <<  "threeSumClosest(): 2 <------> " << s.threeSumClosest(example1, 1) << "\n";
    std::cout <<  "threeSumClosest(): 3 <------> " << s.threeSumClosest(example2, 1) << "\n";
    std::cout << std::endl;
    return 0;
}
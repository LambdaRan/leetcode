
#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <utility>
#include <iterator>
#include <string>
#include <vector>

using namespace std;
/*
* Name: 167. Two Sum II - Input array is sorted
* Website: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
* Description: 
*
*/
class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    vector<int> twoSum_v2(vector<int>& numbers, int target) {
        
        int lidx = 0;
        int ridx = static_cast<int>(numbers.size())-1;
        while (lidx < ridx)
        {
            int sum = numbers[lidx] + numbers[ridx];
            if (sum == target)
                return vector<int>{lidx+1, ridx+1};
            if (sum < target) ++lidx;
            else --ridx;
        }
        return vector<int>();
    }
    vector<int> twoSum_v1(vector<int>& numbers, int target) {
        
        int remain = 0;
        for (size_t i = 0; i < numbers.size(); ++i)
        {
            remain = target - numbers[i];
            auto ret = lower_bound(numbers.begin()+i+1, numbers.end(), remain);
            if (ret != numbers.end() && *ret == remain)
            {
                int second = distance(numbers.begin(), ret);
                return {i+1, second+1};
            }
        }
        return vector<int>();
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
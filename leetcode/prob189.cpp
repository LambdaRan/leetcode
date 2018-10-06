
#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <utility>
#include <iterator>
#include <string>
#include <vector>
#include <map>

using namespace std;
/*
* Name: 189. Rotate Array
* Website: https://leetcode.com/problems/rotate-array/description/
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
    void rotate(vector<int>& nums, int k) {
        if (nums.empty()) return;
        k = k % nums.size();
        std::rotate(nums.begin(), nums.begin()+(nums.size()-k), nums.end());
    }
    // 方法：使用翻转
    // 1.翻转全部 2.翻转前k个元素 3.翻转剩下的元素
    // Let n=7n=7 and k=3k=3.
    // Original List                   : 1 2 3 4 5 6 7
    // After reversing all numbers     : 7 6 5 4 3 2 1
    // After reversing first k numbers : 5 6 7 4 3 2 1
    // After revering last n-k numbers : 5 6 7 1 2 3 4 --> Result
    void rotate_1(vector<int>& nums, int k)
    {
        k %= nums.size();
        reverse(nums, 0, nums.size()-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, nums.size()-1);
    }
    void reverse(vector<int>& nums, int start, int end)
    {
        while (start < end)
            std::swap(nums[start++], nums[end--]);
    }
    void rotate_v2(vector<int>& nums, int k) {
        if (nums.empty()) return;
        k = k % nums.size();
        _rotate(nums, 0, nums.size()-k, nums.size());
    }
    void _rotate(vector<int>& nums, int first, int n_first, int last)
    {
        if (first == n_first) return;
        if (n_first == last) return;

        int next = n_first;
        do {
            std::swap(nums[first++], nums[next++]);
            if (first == n_first) n_first = next;
        } while (next != last);

        for (next = n_first; next != last; )
        {
            std::swap(nums[first++], nums[next++]);
            if(first == n_first) n_first = next;
            else if(next == last) next = n_first;
        }
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

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
* Name: 88.Merge Sorted Array
* Website: https://leetcode.com/problems/merge-sorted-array/
* Description: 
*
*/
class Solution {
public:
    /*
    * Runtime:    ms
    * Your runtime beats  % of cpp submissions. 
    */
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int sumIndex = m + n - 1;
        m -= 1;
        n -= 1;
        for (; m >= 0 && n >= 0; --sumIndex)
        {
            if (nums1[m] >= nums2[n])
                nums1[sumIndex] = nums1[m--];
            else  
                nums1[sumIndex] = nums2[n--];
        }
        for (; n >= 0; --n)
            nums1[sumIndex--] = nums2[n];
    }
};
std::string boolToString(bool input) {
    return input ? "True" : "False";
}
int main() 
{
    Solution s;

    std::cout << "method 1: \n";
    //std::cout <<  "function(): true <------> " << boolToString(s.function()) << "\n";

    std::cout << std::endl;
    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

#include "gtest/gtest.h"

using namespace std;

// Name: 33. Search in Rotated Sorted Array
// Website: https://leetcode.com/problems/search-in-rotated-sorted-array/
// Description:

class Solution {

  public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int li = 0;
        int hi = n - 1;
        while (li < hi) {
            int mi = (li + hi) / 2;
            if (nums[mi] > nums[hi]) {
                li = mi + 1;
            } else {
                hi = mi;
            }
        }

        int smi = li;

        li = 0;
        hi = n - 1;

        while (li <= hi) {
            int mi = (li + hi) / 2;
            int rmi = (mi + smi) % n;
            if (nums[rmi] == target) {
                return rmi;
            }

            if (nums[rmi] < target) {
                li = mi + 1;
            } else {
                hi = mi - 1;
            }
        }
        return -1;
    }


};

Solution solu;

int main() {
    std::vector<int> v = {4,5,6,7,0,1,2};
    int target = 0;

    std::cout << "search:" << solu.search(v, target) << std::endl;
}
// TEST(Fuction, one) {}
#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""

"""

# Name: 33. Search in Rotated Sorted Array
# Website: https://leetcode.com/problems/search-in-rotated-sorted-array/
# Description:
import sys


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        n = len(nums)
        li, hi = 0, n-1
        while li < hi:
            mi = (li + hi) // 2
            if nums[mi] > nums[hi]:
                li = mi + 1
            else:
                hi = mi
        smi = li
        li, hi = 0, n-1
        while li <= hi:
            mi = (li + hi) // 2
            rmi = (mi + smi) % n
            if nums[rmi] == target:
                return rmi
            if nums[rmi] < target:
                li = mi + 1
            else:
                hi = mi - 1
        return -1

    def search_v2(self, nums: List[int], target: int) -> int:
        n = len(nums)
        l = 0
        r = n - 1
        while l <= r:
            mid = (l + r) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] >= nums[l]:
                if target < nums[mid] and target >= nums[l]:
                    r = mid - 1
                else:
                    l = mid + 1
            else:
                if target <= nums[r] and target > nums[mid]:
                    l = mid + 1
                else:
                    r = mid - 1
        return -1


if __name__ == "__main__":
    pass
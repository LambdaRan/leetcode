#!/usr/bin/env python3
#-*- coding:utf-8 -*-

# author    : lambda RDG
# Date&Time : 2019/03/21 20:03:09

"模块的文档注释"
# Name: 448. Find All Numbers Disappeared in an Array
# Website: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/
# Description: 

import sys

class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        ret = []
        for i in range(len(nums)):
            index = abs(nums[i]) - 1
            if nums[index] > 0:
                nums[index] = -nums[index]
        for i in range(len(nums)):
            if nums[i] > 0:
                ret.append(i+1)
        return ret


if __name__ == "__main__":
    pass
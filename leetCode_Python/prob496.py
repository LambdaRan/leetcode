#!/usr/bin/env python3
#-*- coding:utf-8 -*-

# author    : lambda RDG
# Date&Time : 2019/04/01 14:41:48

"模块的文档注释"
# Name: 496. Next Greater Element I
# Website: https://leetcode.com/problems/next-greater-element-i/
# Description:
import sys

class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        idxMap = {}
        for i, v in enumerate(nums2):
            idxMap[v] = i
        res = []
        for v in nums1:
            index = idxMap[v]
            find = -1
            for v2 in nums2[index:]:
                if v2 > v :
                    find = v2
                    break
            res.append(find)
        return res
        


if __name__ == "__main__":
    pass
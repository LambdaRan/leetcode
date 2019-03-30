#!/usr/bin/env python3
#-*- coding:utf-8 -*-

# author    : lambda RDG
# Date&Time : 2019/03/30 11:27:45

"模块的文档注释"

# Name: 485. Max Consecutive Ones 
# Website: https://leetcode.com/problems/max-consecutive-ones/ 
# Description:
import sys

class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        maxCon = 0
        curCon = 0
        for v in nums:
            if v == 0:
                maxCon = max(maxCon, curCon)
                curCon = 0
                continue
            curCon += v
        maxCon = max(maxCon, curCon)
        return maxCon

if __name__ == "__main__":
    pass
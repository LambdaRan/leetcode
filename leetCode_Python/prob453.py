#!/usr/bin/env python3
#-*- coding:utf-8 -*-

# author    : lambda RDG
# Date&Time : 2019/03/22 13:01:03

"模块的文档注释"
# Name: 453. Minimum Moves to Equal Array Elements
# Website: https://leetcode.com/problems/minimum-moves-to-equal-array-elements/description/
# Description: 

import sys
# 这是一个数学计算问题
# 最后状态为所有数值相等，因此得到 n*x = sum + m * (n - 1)
# n : 数组大小； x：最终相等时的数值； sum：初始数组的元素和；m：最小移动次数
# 其中 x=minEle+m
# （minEle+m）*n = sum + m * (n - 1)
# m = sum-minEle*n
class Solution:
    def minMoves(self, nums: List[int]) -> int:
        allSum = sum(nums)
        minEle = min(nums)
        return allSum-minEle*len(nums)

if __name__ == "__main__":
    pass
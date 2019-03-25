#!/usr/bin/env python3
#-*- coding:utf-8 -*-

# author    : lambda RDG
# Date&Time : 2019/03/23 23:09:49

"模块的文档注释"
# Name: 461. Hamming Distance
# Website: https://leetcode.com/problems/hamming-distance/description/
# Description: 
import sys

class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        return bin(x^y).count('1')
        # sum(((x ^ y) >> n) & 1 != 0 for n in range(32))
        # x = x ^ y
        # y = 0
        # while x:
        #     y += 1
        #     x = x & (x - 1)
        # return y
                



if __name__ == "__main__":
    pass


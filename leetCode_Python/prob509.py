#!/usr/bin/env python3
#-*- coding:utf-8 -*-

# author    : lambda RDG
# Date&Time : 2019/05/23 19:32:34

"模块的文档注释"
# Name: 500. Keyboard Row
# Website: https://leetcode.com/problems/keyboard-row/
# Description:
import sys

class Solution:
    def fib(self, N: int) -> int:
        if N < 2: return N
        cur = 1
        prev = 0
        for i in range(1, N):  
             (cur, prev) = (cur + prev, cur)
        return cur
if __name__ == "__main__":
    pass
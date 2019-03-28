#!/usr/bin/env python3
#-*- coding:utf-8 -*-

# author    : lambda RDG
# Date&Time : 2019/03/28 20:07:01

"模块的文档注释"
# Name: 476. Number Complement
# Website: https://leetcode.com/problems/number-complement/
# Description:
import sys

class Solution:
    def findComplement(self, num: int) -> int:
        s = bin(num)[2:]
        res = ''
        for i in range(len(s)):
            if s[i] == '0':
                res += '1'
            else
                res += '0'
        return int(res, 2)


if __name__ == "__main__":
    pass
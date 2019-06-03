#!/usr/bin/env python3
#-*- coding:utf-8 -*-

# author    : lambda RDG
# Date&Time : 2019/06/03 16:38:51
"模块的文档注释"
# Name: 520. Detect Capital
# Website: https://leetcode.com/problems/detect-capital/
# Description:
import sys

class Solution:
    def findLUSlength(self, a: str, b: str) -> int:
        if a == b:
            return -1
        else:
            return max(len(a), len(b))

if __name__ == "__main__":
    pass
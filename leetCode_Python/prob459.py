#!/usr/bin/env python3
#-*- coding:utf-8 -*-

# author    : lambda RDG
# Date&Time : 2019/03/23 23:09:49

"模块的文档注释"
# Name: 459. Repeated Substring Pattern
# Website: https://leetcode.com/problems/repeated-substring-pattern/description/
# Description: 
import sys

class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        if not s:
            return False
        return s in (s + s)[1:-1]
                



if __name__ == "__main__":
    pass
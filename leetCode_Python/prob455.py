#!/usr/bin/env python3
#-*- coding:utf-8 -*-

# author    : lambda RDG
# Date&Time : 2019/03/23 23:09:49

"模块的文档注释"
# Name: 455. Assign Cookies
# Website: https://leetcode.com/problems/assign-cookies/description/
# Description: 
import sys

class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort()
        s.sort()
        ret = 0;
        gi, si = len(g)-1, len(s)-1
        while si >= 0:
            if gi < 0:
                break
            if s[si] >= g[gi]:
                ret += 1
                si -= 1
            gi -= 1
        # j = 0
        # for w in s:
        #     if j < len(g) and w >= g[j]: j += 1
        return ret
                



if __name__ == "__main__":
    pass
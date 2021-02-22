#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""

"""

# Name: 22. Generate Parentheses
# Website: https://leetcode.com/problems/generate-parentheses/
# Description:
import sys


class Solution:
    def generateParenthesis(self, N):
        ans = []
        def backtrack(s="", l=0, r=0):
            if len(s) == 2 * N:
                ans.append(s)
            if l < N:
                backtrack(s+"(", l+1, r)
            if r < l:
                backtrack(s+")", l, r+1)
        backtrack()
        return ans

if __name__ == "__main__":
    pass
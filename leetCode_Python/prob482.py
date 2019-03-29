#!/usr/bin/env python3
#-*- coding:utf-8 -*-

# author    : lambda RDG
# Date&Time : 2019/03/29 20:49:37

"模块的文档注释"
# Name: 476. Number Complement
# Website: https://leetcode.com/problems/number-complement/
# Description:
import sys
class Solution:
    def licenseKeyFormatting(self, S: str, K: int) -> str:
        S = S.replace('-','').upper()
        n = len(S)
        head = n % K
        res = [S[:head]] if head else []
        for i in range(head, n, K):
            res.append(S[i:i+K])
        return '-'.join(res)   


if __name__ == "__main__":
    pass
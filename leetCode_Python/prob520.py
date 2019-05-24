#!/usr/bin/env python3
#-*- coding:utf-8 -*-

# author    : lambda RDG
# Date&Time : 2019/05/24 19:22:58

"模块的文档注释"
# Name: 520. Detect Capital
# Website: https://leetcode.com/problems/detect-capital/
# Description:
import sys

class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        cntUpper = 0
        cntLower = 0
        for ch in word[1:]:
            if ch.isupper():
                cntUpper = cntUpper + 1
            else: 
                cntLower = cntLower + 1
        if word[0].islower():
            return len(word)-1 == cntLower
        else:
            return len(word)-1 == max(cntUpper, cntLower)

def detectCapitalUse2(self, word: str) -> bool:
    count=0
    for i in range(len(word)):
        if word[i].isupper():
            count+=1
            
    return len(word)==count or count==0 or (count==1 and word[0].isupper
    
#return word.isupper() or word.islower() or word.istitle()

if __name__ == "__main__":
    pass
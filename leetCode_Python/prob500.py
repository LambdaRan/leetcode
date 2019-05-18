#!/usr/bin/env python3
#-*- coding:utf-8 -*-

# author    : lambda RDG
# Date&Time : 2019/05/17 16:26:37

"模块的文档注释"
# Name: 500. Keyboard Row
# Website: https://leetcode.com/problems/keyboard-row/
# Description:
import sys

class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        result = []
        if not words: 
            return result
        alphabets = ("qwertyuiop", "asdfghjkl", "zxcvbnm")
        alphabetToRows = {}
        for i, alpha in enumerate(alphabets):
            for v in alpha:
                alphabetToRows[v] = i
        for word in words:
            if word:
                isOneRow = True
                for ch in word:
                    if alphabetToRows[word[0]] != alphabetToRows[ch]:
                        isOneRow = False
                        break
            if isOneRow:
                result.append(word)
        return result
        # keyboard = [set('qwertyuiop'),set('asdfghjkl'),set('zxcvbnm')]
        # output=list()
        # for word in words:
        #     if sum([1 for row in keyboard if set(word.lower()).intersection(row)])==1:
        #         output.append(word)
                
        # return output



if __name__ == "__main__":
    pass
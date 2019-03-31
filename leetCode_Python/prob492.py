#!/usr/bin/env python3
#-*- coding:utf-8 -*-

# author    : lambda RDG
# Date&Time : 2019/03/31 20:33:08

"模块的文档注释"
# Name: 492. Construct the Rectangle
# Website: https://leetcode.com/problems/construct-the-rectangle/
# Description:
import sys

class Solution:
    def constructRectangle(self, area: int) -> List[int]:
        import math
        w = int(math.sqrt(area))
        while area % w:
            w -= 1
        return [area//w, w]

if __name__ == "__main__":
    pass
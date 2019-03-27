#!/usr/bin/env python3
#-*- coding:utf-8 -*-

# author    : lambda RDG
# Date&Time : 2019/03/27 16:59:50

"模块的文档注释"
# Name: 475. Heaters
# Website: https://leetcode.com/problems/heaters/
# Description: 
import sys

class Solution(object):
    def findRadius(self, houses, heaters):
        houses.sort()
        heaters.sort()
        heaters = [float('-inf')]+heaters+[float('inf')]
        ans, i = 0, 0
        for house in houses:
            while house > heaters[i+1]:
                i += 1
            dis = min(house-heaters[i], heaters[i+1]-house)
            ans = max(ans, dis)
        return ans

if __name__ == "__main__":
    pass
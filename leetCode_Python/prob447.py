#!/usr/bin/env python3
#-*- coding:utf-8 -*-

# author    : lambda RDG
# Date&Time : 2019/3/18 9:23

"模块的文档注释"

import sys

class Solution:
    def numberOfBoomerangs(self, points: List[List[int]]) -> int:
            res = 0
            for p in points:
                distMap = {}
                for q in points:
                    l = p[0] - q[0]
                    w = p[1] - q[1]
                    dist = l*l + w*w
                    distMap[dist] = 1 + distMap.get(dist, 0)
                for d in distMap:
                    res += distMap[d] * (distMap[d] - 1)
            return res

if __name__ == "__main__":
    pass
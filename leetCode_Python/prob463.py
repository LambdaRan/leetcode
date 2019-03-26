#!/usr/bin/env python3
#-*- coding:utf-8 -*-

# author    : lambda RDG
# Date&Time : 2019/03/26 18:28:44

"模块的文档注释"
# Name: 463. Island Perimeter
# Website: https://leetcode.com/problems/island-perimeter/
# Description: 
import sys

class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        rows = len(grid)
        cols = len(grid[0])
        island = 0
        nei = 0
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 1:
                    island += 1
                    if i < rows-1:
                        nei += grid[i + 1][j]
                    if j < cols-1:
                        nei += grid[i][j + 1] 
        return island * 4 - nei * 2;

if __name__ == "__main__":
    pass
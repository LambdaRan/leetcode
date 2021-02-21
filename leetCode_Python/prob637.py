#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""

"""

# Name: 637. Average of Levels in Binary Tree
# Website: https://leetcode.com/problems/average-of-levels-in-binary-tree/
# Description:
import sys
from collections import defaultdict


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfLevels(self, root):
        if root is None:
            return []
        levels = defaultdict(list)
        queue = [(root, 1)]
        level = 0
        while queue:
            node, level = queue.pop(0)
            levels[level].append(node.val)
            if node.left is not None:
                queue.append((node.left, level + 1))
            if node.right is not None:
                queue.append((node.right, level + 1))
        return [sum(levels[i]) / len(levels[i]) for i in range(1, level + 1)]


if __name__ == "__main__":
    pass
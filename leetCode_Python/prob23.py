#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""

"""

# Name: 23. Merge k Sorted Lists
# Website: https://leetcode.com/problems/merge-k-sorted-lists/
# Description:
import sys
from Queue import PriorityQueue

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists):
        amount = len(lists)
        interval = 1
        while interval < amount:
            for i in range(0, amount-interval, interval*2):
                lists[i] = self.merge2List(lists[i], lists[i+interval])
            interval *= 2
        return lists[0] if amount == 0 else None

    def merge2List(self, l1, l2):
        head = point = ListNode(0)
        while l1 and l2:
            if l1.val <= l2.val:
                point.next = l1
                l1 = l1.next
            else:
                point.next = l2
                l2 = l2.next
            point = point.next
        if l1:
            point.next = l1
        if l2:
            point.next = l2
        return head.next

    # from Queue import PriorityQueue
    def mergeKLists_v2(self, lists):
        head = point = ListNode(0)
        nq = PriorityQueue()
        for l in lists:
            if l:
                nq.push((l.val, l))
        while not nq.empty():
            val, node = nq.get()
            point.next = node
            point = point.next
            node = node.next
            if node:
                nq.push((node.val, node))
        return head.next

    # from queue import PriorityQueue
    def mergeKLists_v2_1(self, lists):
        class Wrapper():
            def __init__(self, node):
                self.node = node
            def __lt__(self, other):
                return self.node.val < other.node.val
        head = point = ListNode(0)
        nq = PriorityQueue()
        for l in lists:
            if l:
                nq.put(Wrapper(l))
        while not nq.empty():
            node = nq.get().node
            point.next = node
            point = point.next
            node = node.next
            if node:
                nq.put(Wrapper(node))
        return head.next


if __name__ == "__main__":
    pass
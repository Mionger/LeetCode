#
# @lc app=leetcode id=23 lang=python3
#
# [23] Merge k Sorted Lists
#
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeKLists(self, lists):
        from heapq import heappush, heappop, heapreplace, heapify
        heap = [(head.val, i, head) for i,head in enumerate(lists) if head]
        heapify(heap)
        dummy = ListNode(0)
        node = dummy
        while heap != []:
            val, i, n = heap[0]
            if not n.next: # exhausted one linked-list
                heappop(heap)
            else:
                heapreplace(heap, (n.next.val, i, n.next)) # recycling tie-breaker i guarantees uniqueness
            node.next = n    
            node = node.next
        return dummy.next


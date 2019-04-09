#
# @lc app=leetcode id=21 lang=python3
#
# [21] Merge Two Sorted Lists
# https://leetcode.com/problems/merge-two-sorted-lists/description/
#
# algorithms
# Easy (46.24%)
# Total Accepted:    533.7K
# Total Submissions: 1.2M
# Testcase Example:  '[1,2,4]\n[1,3,4]'
#
# Merge two sorted linked lists and return it as a new list. The new list
# should be made by splicing together the nodes of the first two lists.
# 
# Example:
# Input: 1->2->4, 1->3->4
# Output: 1->1->2->3->4->4
# 
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        result = ListNode(-1)
        l = result
        while l1 and l2:
            if l1.val <= l2.val:
                l.next = l1
                l1 = l1.next
            else:
                l.next = l2
                l2 = l2.next
            l = l.next
        l.next = l1 or l2
        return result.next
    
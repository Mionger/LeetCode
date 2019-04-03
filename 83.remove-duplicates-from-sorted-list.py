#
# @lc app=leetcode id=83 lang=python3
#
# [83] Remove Duplicates from Sorted List
# https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
#
# algorithms
# Easy (42.11%)
# Total Accepted:    310.9K
# Total Submissions: 738.1K
# Testcase Example:  '[1,1,2]'
#
# Given a sorted linked list, delete all duplicates such that each element
# appear only once.
# 
# Example 1:
# Input: 1->1->2
# Output: 1->2
# 
# 
# Example 2:
# Input: 1->1->2->3->3
# Output: 1->2->3
# 
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: 'ListNode') -> 'ListNode':
        L = head
        temp = L
        while not temp is None:
            if temp.next is None:
                break
            else:
                if temp.val == temp.next.val:
                    t = temp.next.next
                    temp.next = t
                else:
                    temp = temp.next
        return L
        

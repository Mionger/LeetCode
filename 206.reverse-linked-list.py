#
# @lc app=leetcode id=206 lang=python3
#
# [206] Reverse Linked List
# https://leetcode.com/problems/reverse-linked-list/description/
#
# algorithms
# Easy (53.56%)
# Total Accepted:    556.5K
# Total Submissions: 1M
# Testcase Example:  '[1,2,3,4,5]'
#
# Reverse a singly linked list.
# 
# Example:
# Input: 1->2->3->4->5->NULL
# Output: 5->4->3->2->1->NULL
# 
# 
# Follow up:
# A linked list can be reversed either iteratively or recursively. Could you
# implement both?
# 
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: 'ListNode') -> 'ListNode':
        if not head or not head.next:
            return head
        pre = None
        while head:
            next = head.next
            head.next = pre
            pre = head
            head = next
        return pre
        
        


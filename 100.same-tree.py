#
# @lc app=leetcode id=100 lang=python3
#
# [100] Same Tree
# https://leetcode.com/problems/same-tree/description/
#
# algorithms
# Easy (49.63%)
# Total Accepted:    360.3K
# Total Submissions: 725.7K
# Testcase Example:  '[1,2,3]\n[1,2,3]'
#
# Given two binary trees, write a function to check if they are the same or
# not.
# 
# Two binary trees are considered the same if they are structurally identical
# and the nodes have the same value.
# 
# Example 1:
# Input:     1         1
# ⁠         / \       / \
# ⁠        2   3     2   3
# 
# ⁠       [1,2,3],   [1,2,3]
# 
# Output: true
# 
# 
# Example 2:
# Input:     1         1
# ⁠         /           \
# ⁠        2             2
# 
# ⁠       [1,2],     [1,null,2]
# 
# Output: false
# 
# 
# Example 3:
# Input:     1         1
# ⁠         / \       / \
# ⁠        2   1     1   2
# 
# ⁠       [1,2,1],   [1,1,2]
# 
# Output: false
# 
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSameTree(self, p: 'TreeNode', q: 'TreeNode') -> 'bool':
        if p is None:
            if q is None:
                return True
            else:
                return False
        else:
            if q is None:
                return False


        queue1 = [p]
        queue2 = [q]
        while len(queue1) != 0 and len(queue2) != 0:
            node1 = queue1[0]
            del queue1[0]
            node2 = queue2[0]
            del queue2[0]
            if node1.val == node2.val:
                if node1.left is None:
                    if not node2.left is None:
                        return False
                else:
                    if node2.left is None:
                        return False
                    else:
                        queue1.append(node1.left)
                        queue2.append(node2.left) 
                if node1.right is None:
                    if not node2.right is None:
                        return False
                else:
                    if node2.right is None:
                        return False
                    else:
                        queue1.append(node1.right)
                        queue2.append(node2.right) 
            else:
                return False
        if queue1 or queue2:
            return False
        else:
            return True

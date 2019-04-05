#
# @lc app=leetcode id=107 lang=python3
#
# [107] Binary Tree Level Order Traversal II
# https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
#
# algorithms
# Easy (46.05%)
# Total Accepted:    215.8K
# Total Submissions: 468.4K
# Testcase Example:  '[3,9,20,null,null,15,7]'
#
# Given a binary tree, return the bottom-up level order traversal of its nodes'
# values. (ie, from left to right, level by level from leaf to root).
# 
# 
# For example:
# Given binary tree [3,9,20,null,null,15,7],
# 
# ⁠   3
# ⁠  / \
# ⁠ 9  20
# ⁠   /  \
# ⁠  15   7
# 
# return its bottom-up level order traversal as:
# 
# [
# ⁠ [15,7],
# ⁠ [9,20],
# ⁠ [3]
# ]
# 
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrderBottom(self, root: 'TreeNode') -> 'List[List[int]]':
        result = []
        if root is None:
            return result
        else:
            queue = [root]
            result.append([root.val])
            while len(queue):
                LevelNodeTotal = len(queue)
                count = 0
                List = []
                while count < LevelNodeTotal:
                    count += 1
                    node = queue[0]
                    del queue[0]
                    if not (node.left is None):
                        queue.append(node.left)
                        List.append(node.left.val)
                    if not (node.right is None):
                        queue.append(node.right)
                        List.append(node.right.val)
                if List != []:
                    result.append(List)
            result.reverse()        
            return result

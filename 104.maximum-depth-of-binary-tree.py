#
# @lc app=leetcode id=104 lang=python3
#
# [104] Maximum Depth of Binary Tree
# https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
#
# algorithms
# Easy (59.71%)
# Total Accepted:    476.8K
# Total Submissions: 798.1K
# Testcase Example:  '[3,9,20,null,null,15,7]'
#
# Given a binary tree, find its maximum depth.
# 
# The maximum depth is the number of nodes along the longest path from the root
# node down to the farthest leaf node.
# 
# Note: A leaf is a node with no children.
# 
# Example:
# Given binary tree [3,9,20,null,null,15,7],
# 
# ⁠   3
# ⁠  / \
# ⁠ 9  20
# ⁠   /  \
# ⁠  15   7
# 
# return its depth = 3.
# 
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxDepth(self, root: 'TreeNode') -> 'int':
        if root is None:
            return 0
        else:
            queue = [root]
            depth = 0
            while len(queue):
                depth += 1
                LevelNodeTotal = len(queue)
                count = 0
                while count < LevelNodeTotal:
                    count += 1
                    node = queue[0]
                    del queue[0]
                    if not (node.left is None):
                        queue.append(node.left)
                    if not (node.right is None):
                        queue.append(node.right)
            return depth

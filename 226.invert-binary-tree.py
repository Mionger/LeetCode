#
# @lc app=leetcode id=226 lang=python3
#
# [226] Invert Binary Tree
#
# https://leetcode.com/problems/invert-binary-tree/description/
#
# algorithms
# Easy (57.50%)
# Total Accepted:    314.9K
# Total Submissions: 545.6K
# Testcase Example:  '[4,2,7,1,3,6,9]'
#
# Invert a binary tree.
# 
# Example:
# 
# Input:
# ⁠    4
# ⁠  /   \
# ⁠ 2     7
# ⁠/ \   / \
# 1   3 6   9
# 
# Output:
# ⁠    4
# ⁠  /   \
# ⁠ 7     2
# ⁠/ \   / \
# 9   6 3   1
# 
# Trivia:
# This problem was inspired by this original tweet by Max Howell:
# 
# Google: 90% of our engineers use the software you wrote (Homebrew), but you
# can’t invert a binary tree on a whiteboard so f*** off.
# 
#
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        # result = []
        if root is None:
            return None
        else:
            queue = [root]
            while len(queue):
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
                    temp = node.right
                    node.right = node.left
                    node.left = temp
            return root


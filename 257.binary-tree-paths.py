#
# @lc app=leetcode id=257 lang=python3
# [257] Binary Tree Paths
#
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def binaryTreePaths(self, root: 'TreeNode') -> 'List[str]':
        


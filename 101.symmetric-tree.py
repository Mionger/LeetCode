#
# @lc app=leetcode id=101 lang=python3
#
# [101] Symmetric Tree
# https://leetcode.com/problems/symmetric-tree/description/
#
# algorithms
# Easy (42.98%)
# Total Accepted:    375.9K
# Total Submissions: 874K
# Testcase Example:  '[1,2,2,3,4,4,3]'
#
# Given a binary tree, check whether it is a mirror of itself (ie, symmetric
# around its center).
# 
# 
# For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
# 
# ⁠   1
# ⁠  / \
# ⁠ 2   2
# ⁠/ \ / \
# 3  4 4  3
# 
# But the following [1,2,2,null,3,null,3]  is not:
# 
# ⁠   1
# ⁠  / \
# ⁠ 2   2
# ⁠  \   \
# ⁠  3    3
# 
# Note:
# Bonus points if you could solve it both recursively and iteratively.
# 
#
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root: 'TreeNode') -> 'bool':
        if root is None:
            return True
        else:
            p = root.left
            q = root.right
            if p is None:
                if q is None:
                    return True
                else:
                    return False
            else:
                if q is None:
                    return False
                else:
                    queue1 = [p]
                    queue2 = [q]
                    while len(queue1) != 0 and len(queue2) != 0:
                        node1 = queue1[0]
                        del queue1[0]
                        node2 = queue2[0]
                        del queue2[0]
                        if node1.val == node2.val:
                            if node1.left is None:
                                if not node2.right is None:
                                    return False
                            else:
                                if node2.right is None:
                                    return False
                                else:
                                    queue1.append(node1.left)
                                    queue2.append(node2.right) 
                            if node1.right is None:
                                if not node2.left is None:
                                    return False
                            else:
                                if node2.left is None:
                                    return False
                                else:
                                    queue1.append(node1.right)
                                    queue2.append(node2.left) 
                        else:
                            return False
                    if queue1 or queue2:
                        return False
                    else:
                        return True


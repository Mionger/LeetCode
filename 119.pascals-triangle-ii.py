#
# @lc app=leetcode id=119 lang=python3
#
# [119] Pascal's Triangle II
# https://leetcode.com/problems/pascals-triangle-ii/description/
#
# algorithms
# Easy (42.65%)
# Total Accepted:    192.9K
# Total Submissions: 451.9K
# Testcase Example:  '3'
#
# Given a non-negative index k where k ≤ 33, return the k^th index row of the
# Pascal's triangle.
# 
# Note that the row index starts from 0.
# 
# 
# In Pascal's triangle, each number is the sum of the two numbers directly
# above it.
# 
# Example:
# Input: 3
# Output: [1,3,3,1]
# 
# Follow up:
# 
# Could you optimize your algorithm to use only O(k) extra space?
# 
#
class Solution:
    def getRow(self, rowIndex: 'int') -> 'List[int]':
        if rowIndex < 0:
            return []

        result = []
        t = 1
        for i in range(rowIndex + 1):
            if i == 0:
                result.append(t)
            else:
                t = t * (rowIndex + 1 - i) // i
                result.append(t)
        return result

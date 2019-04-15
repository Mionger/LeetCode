#
# @lc app=leetcode id=172 lang=python3
#
# [172] Factorial Trailing Zeroes
# https://leetcode.com/problems/factorial-trailing-zeroes/description/
#
# algorithms
# Easy (37.30%)
# Total Accepted:    152.1K
# Total Submissions: 407.6K
# Testcase Example:  '3'
#
# Given an integer n, return the number of trailing zeroes in n!.
# 
# Example 1:
# Input: 3
# Output: 0
# Explanation: 3! = 6, no trailing zero.
# 
# Example 2:
# Input: 5
# Output: 1
# Explanation: 5! = 120, one trailing zero.

# Note: Your solution should be in logarithmic time complexity.

class Solution:
    def trailingZeroes(self, n: 'int') -> 'int':
        result = 0
        while n > 0:
            n = n // 5
            result += n
        return result       


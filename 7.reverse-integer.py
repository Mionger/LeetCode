#
# @lc app=leetcode id=7 lang=python3
#
# [7] Reverse Integer
# https://leetcode.com/problems/reverse-integer/description/
#
# algorithms
# Easy (25.21%)
# Total Accepted:    636.3K
# Total Submissions: 2.5M
# Testcase Example:  '123'
#
# Given a 32-bit signed integer, reverse digits of an integer.
# 
# Example 1:
# Input: 123
# Output: 321
# 
# 
# Example 2:
# Input: -123
# Output: -321
# 
# 
# Example 3:
# Input: 120
# Output: 21
# 
# Note:
# Assume we are dealing with an environment which could only store integers
# within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose
# of this problem, assume that your function returns 0 when the reversed
# integer overflows.
# 
class Solution:
    def reverse(self, x: 'int') -> 'int':
        sign = 1
        if x < 0:
            sign = -1
        num = 0
        x = abs(x)
        while x > 0:
            d = x % 10 
            x = x // 10
            num = num*10 + d
        if (num> (2**31) -1):
            return 0
        return num * sign
        

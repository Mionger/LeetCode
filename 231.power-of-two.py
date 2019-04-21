#
# @lc app=leetcode id=231 lang=python3
#
# [231] Power of Two
# https://leetcode.com/problems/power-of-two/description/
#
# algorithms
# Easy (41.75%)
# Total Accepted:    221.8K
# Total Submissions: 530.4K
# Testcase Example:  '1'
#
# Given an integer, write a function to determine if it is a power of two.
# 
# Example 1:
# Input: 1
# Output: true 
# Explanation: 2^0 = 1
# 
# Example 2:
# Input: 16
# Output: true
# Explanation: 2^4 = 16
# 
# Example 3:
# Input: 218
# Output: false
# 
#
class Solution:
    def isPowerOfTwo(self, n: 'int') -> 'bool':
        if n == 1:
            return True
        elif n == 0:
            return False
        else:
            while True:
                if n == 2:
                        return True
                if n & 1:
                    return False
                else:
                    n = n >> 1


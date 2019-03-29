#
# @lc app=leetcode id=28 lang=python3
#
# [28] Implement strStr()
# https://leetcode.com/problems/implement-strstr/description/
#
# algorithms
# Easy (31.48%)
# Total Accepted:    397.3K
# Total Submissions: 1.3M
# Testcase Example:  '"hello"\n"ll"'
#
# Implement strStr().
# 
# Return the index of the first occurrence of needle in haystack, or -1 if
# needle is not part of haystack.
# 
# Example 1:
# Input: haystack = "hello", needle = "ll"
# Output: 2
# 
# Example 2:
# Input: haystack = "aaaaa", needle = "bba"
# Output: -1
# 
# 
# Clarification:
# 
# What should we return when needle is an empty string? This is a great
# question to ask during an interview.
# 
# For the purpose of this problem, we will return 0 when needle is an empty
# string. This is consistent to C's strstr() and Java's indexOf().
# 
#
class Solution:
    def strStr(self, haystack: 'str', needle: 'str') -> 'int':
        if needle == "":
            return 0
        result = -1
        L = len(haystack)
        l = len(needle)
        if L < l:
            return -1
        i = 0
        j = 0
        while i < L:
            if L - result < l:
                return -1
            if j < l:
                if haystack[i] == needle[j]:
                    if j == 0:
                        result = i
                    j = j + 1
                else:
                    if not j == 0:
                        j = 0
                        i = result
                        result = -1
            i = i + 1
        return result

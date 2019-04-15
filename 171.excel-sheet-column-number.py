#
# @lc app=leetcode id=171 lang=python3
#
# [171] Excel Sheet Column Number
#
# https://leetcode.com/problems/excel-sheet-column-number/description/
#
# algorithms
# Easy (51.11%)
# Total Accepted:    213.5K
# Total Submissions: 417.2K
# Testcase Example:  '"A"'
#
# Given a column title as appear in an Excel sheet, return its corresponding
# column number.
# 
# For example:
# 
# 
# ⁠   A -> 1
# ⁠   B -> 2
# ⁠   C -> 3
# ⁠   ...
# ⁠   Z -> 26
# ⁠   AA -> 27
# ⁠   AB -> 28 
# ⁠   ...
# 
# 
# Example 1:
# 
# 
# Input: "A"
# Output: 1
# 
# 
# Example 2:
# 
# 
# Input: "AB"
# Output: 28
# 
# 
# Example 3:
# 
# 
# Input: "ZY"
# Output: 701
# 
#
class Solution:
    def titleToNumber(self, s: 'str') -> 'int':
        n = 0
        dic = {
                'A':1,
                'B':2,
                'C':3,
                'D':4,
                'E':5,
                'F':6,
                'G':7,
                'H':8,
                'I':9,
                'J':10,
                'K':11,
                'L':12,
                'M':13,
                'N':14,
                'O':15,
                'P':16,
                'Q':17,
                'R':18,
                'S':19,
                'T':20,
                'U':21,
                'V':22,
                'W':23,
                'X':24,
                'Y':25,
                'Z':26
            }
        temp = 1 
        L = len(s)
        for i in range(L):
            n += temp * dic[s[L-1-i]]
            temp *= 26
        return n

#
# @lc app=leetcode id=67 lang=python3
#
# [67] Add Binary
# https://leetcode.com/problems/add-binary/description/
#
# algorithms
# Easy (38.30%)
# Total Accepted:    285.5K
# Total Submissions: 744.6K
# Testcase Example:  '"11"\n"1"'
#
# Given two binary strings, return their sum (also a binary string).
# 
# The input strings are both non-empty and contains only characters 1 or 0.
# 
# Example 1:
# Input: a = "11", b = "1"
# Output: "100"
# 
# Example 2:
# Input: a = "1010", b = "1011"
# Output: "10101"
# 
#
class Solution:
    def addBinary(self, a: 'str', b: 'str') -> 'str':
        la = len(a)
        lb = len(b)
        i = la - 1
        j = lb - 1
        c = ""
        flag = 0
        if la > lb:
            while j >= 0:
                if a[i] == b[j]:
                    if flag == 0:
                        c = '0' + c
                    else:
                        c = '1' + c
                    if b [j] == '1':
                        flag = 1
                    else:
                        flag = 0 
                else:
                    if flag == 1:
                        c = '0' + c
                        flag = 1
                    else:
                        c = '1' + c
                        flag = 0
                i -= 1
                j -= 1
            while i >= 0:
                if a[i] == '0':
                    if flag == 0:
                        c = '0' + c
                    else:
                        c = '1' + c
                        flag = 0
                else:
                    if flag == 0:
                        c = '1' + c
                    else:
                        c = '0' + c
                        flag = 1
                i -= 1
            if flag == 1:
                return '1' + c
            else:
                return c
        else:
            while i >= 0:
                if b[j] == a[i]:
                    if flag == 0:
                        c = '0' + c
                    else:
                        c = '1' + c
                    if a [i] == '1':
                        flag = 1
                    else:
                        flag = 0 
                else:
                    if flag == 1:
                        c = '0' + c
                        flag = 1
                    else:
                        c = '1' + c
                        flag = 0
                j -= 1
                i -= 1
            while j >= 0:
                if b[j] == '0':
                    if flag == 0:
                        c = '0' + c
                    else:
                        c = '1' + c
                        flag = 0
                else:
                    if flag == 0:
                        c = '1' + c
                    else:
                        c = '0' + c
                        flag = 1
                j -= 1
            if flag == 1:
                return '1' + c
            else:
                return c

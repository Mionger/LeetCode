#
# @lc app=leetcode id=168 lang=python3
#
# [168] Excel Sheet Column Title
#
# https://leetcode.com/problems/excel-sheet-column-title/description/
#
# algorithms
# Easy (28.69%)
# Total Accepted:    167.5K
# Total Submissions: 583.4K
# Testcase Example:  '1'
#
# Given a positive integer, return its corresponding column title as appear in
# an Excel sheet.
# 
# For example:
# 
# 
# ⁠   1 -> A
# ⁠   2 -> B
# ⁠   3 -> C
# ⁠   ...
# ⁠   26 -> Z
# ⁠   27 -> AA
# ⁠   28 -> AB 
# ⁠   ...
# 
# 
# Example 1:
# Input: 1
# Output: "A"
# 
# Example 2:
# Input: 28
# Output: "AB"
# 
# Example 3:
# Input: 701
# Output: "ZY"
# 

class Solution:
    def convertToTitle(self, n: 'int') -> 'str':
        n -= 1
        s = ""
        dic = {
                0:'A',
                1:'B',
                2:'C',
                3:'D',
                4:'E',
                5:'F',
                6:'G',
                7:'H',
                8:'I',
                9:'J',
                10:'K',
                11:'L',
                12:'M',
                13:'N',
                14:'O',
                15:'P',
                16:'Q',
                17:'R',
                18:'S',
                19:'T',
                20:'U',
                21:'V',
                22:'W',
                23:'X',
                24:'Y',
                25:'Z'
            }
        while True:
            temp = n % 26
            if temp < 0:
                s = dic[26 + temp] + s
            else:
                s = dic[temp] + s
            if n < 26:
                break
            else:
                n  = n // 26
                n -= 1
        return s

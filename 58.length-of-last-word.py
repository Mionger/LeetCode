#
# @lc app=leetcode id=58 lang=python3
#
# [58] Length of Last Word
# https://leetcode.com/problems/length-of-last-word/description/
#
# algorithms
# Easy (32.18%)
# Total Accepted:    253.6K
# Total Submissions: 787.8K
# Testcase Example:  '"Hello World"'
#
# Given a string s consists of upper/lower-case alphabets and empty space
# characters ' ', return the length of last word in the string.
# 
# If the last word does not exist, return 0.
# 
# Note: A word is defined as a character sequence consists of non-space
# characters only.
# 
# Example:
# Input: "Hello World"
# Output: 5
# 
# 
#
class Solution:
    def lengthOfLastWord(self, s: 'str') -> 'int':
        if s == "":
            return 0
        L = len(s)
        count = 0 
        for i in range(L):
            if L - 1 - i == 0:
                if s[L - 1 - i] == " ":
                    return count
                else:
                    count += 1
                    return count
            else:
                if s[L - 1 - i] == " ":
                    if count != 0:
                        return count
                    else:
                        continue
                else:
                    count += 1

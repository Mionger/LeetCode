#
# @lc app=leetcode id=205 lang=python3
#
# [205] Isomorphic Strings
# https://leetcode.com/problems/isomorphic-strings/description/
#
# algorithms
# Easy (36.95%)
# Total Accepted:    195.8K
# Total Submissions: 528.6K
# Testcase Example:  '"egg"\n"add"'
#
# Given two strings s and t, determine if they are isomorphic.
# 
# Two strings are isomorphic if the characters in s can be replaced to get t.
# 
# All occurrences of a character must be replaced with another character while
# preserving the order of characters. No two characters may map to the same
# character but a character may map to itself.
# 
# Example 1:
# Input: s = "egg", t = "add"
# Output: true
# 
# 
# Example 2:
# Input: s = "foo", t = "bar"
# Output: false
# 
# Example 3:
# Input: s = "paper", t = "title"
# Output: true
# 
# Note:
# You may assume both s and t have the same length.
# 

class Solution:
    def isIsomorphic(self, s: 'str', t: 'str') -> 'bool':
        if not s:
            if not t:
                return True
            else:
                return False
        else:
            if not t:
                return False
            else:
                Ls = len(s)
                Lt = len(t)
                if Ls != Lt:
                    return False
                else:
                    dict_s = {}
                    dict_t = {}
                    for i in range(Ls):
                        if dict_s.get(s[i],-1) == -1 and dict_t.get(t[i],-1) == -1:
                            dict_s[s[i]] = i
                            dict_t[t[i]] = i
                        if dict_s.get(s[i],-1) != dict_t.get(t[i],-1):
                            return False
                    return True

                

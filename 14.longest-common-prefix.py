#
# @lc app=leetcode id=14 lang=python3
#
# [14] Longest Common Prefix
# https://leetcode.com/problems/longest-common-prefix/description/
#
# algorithms
# Easy (33.13%)
# Total Accepted:    426.9K
# Total Submissions: 1.3M
# Testcase Example:  '["flower","flow","flight"]'
#
# Write a function to find the longest common prefix string amongst an array of strings.
# 
# If there is no common prefix, return an empty string "".
# 
# Example 1:
# Input: ["flower","flow","flight"]
# Output: "fl"
# 
# Example 2:
# Input: ["dog","racecar","car"]
# Output: ""
# Explanation: There is no common prefix among the input strings.
# 
# Note:
# All given inputs are in lowercase letters a-z.
# 

class Solution:
    def longestCommonPrefix(self, strs):
        result = ""

        if len(strs) == 0:
            return result
        
        minlen = len(strs[0])
        for string  in strs:
            minlen = min(minlen , len(string))

        for i in range(minlen):
            ch = strs[0][i]
            for string in strs:
                if ch != string[i]:
                    return result
            result = result + ch
        
        return result

